/*
*  Author: HIT CS HDMC team.
*  Create: 2010-3-13 8:50:12
*  Last modified: 2010-6-16 14:08:59
*  Description:
*  	Memory fault injection tool.
*/
#include <sys/wait.h>
#include <signal.h>
#include "memoryInjector.h"
#include "memoryEngine.h"


static int childProcess;	//for cleanup
static long inject_pa;
static long newData;
static long origData;

static int signalPid;

Injector::Injector()
{
	faultTablePath.clear();
	targetPid = -1;
	exeArguments = NULL;
}

Injector::~Injector()
{
	faultTable.clear();
}

Injector * Injector::initInjector( int argc, char **argv )
{
	Injector * pInjector = new Injector();
	if( pInjector == NULL ) { return NULL; }
	
	/// get arguments
	while(argc > 0)
	{
		argc--;
		argv++;
		
		if(strcmp(argv[0],"-c") == 0)
		{
			pInjector->faultTablePath = argv[1];
			argv++;
		}
		else if(strcmp(argv[0],"-e") == 0)
		{
			pInjector->exeArguments = argv + 1;
			break;
		}
		else if(strcmp(argv[0],"-p") == 0)
		{
			pInjector->targetPid = atoi(argv[1]);
			break;
		}
		else
		{
			printf("Unknown option: %s\n",argv[0]);
			pInjector->usage();
			delete( pInjector );
			return NULL;
		}
	}
	
	if( pInjector->initFaultTable() == RT_FAIL )
	{
		delete( pInjector );
		return NULL;
	}
	return pInjector;
}

int Injector::initFaultTable( void )
{
	string line;
	if( faultTablePath.empty() )
	{ 
		cerr << "Error:no existing fault table" << endl;
		return RT_FAIL; 
	}
	ifstream infile;
	infile.open( faultTablePath.c_str(), ios::in );
	if( !infile )
	{
		cerr << "Error:unable to open file:" << faultTablePath << endl;
		return RT_FAIL;
	}
	string strLine;
	string strTmp;
	memFault  faultTmp;
	while( getline(infile,strLine,'\n') )
	{
		//bind istream to the strLine
		istringstream stream(strLine);
		
		/// location: text or data
		strTmp.clear();
		stream >> strTmp;
		if( strTmp.empty() )
		{
			cerr << "Error:fault table format errno" << endl;
			return RT_FAIL;
		}
		else if( strTmp == "text" || strTmp == "TEXT" )
		{
			faultTmp.location = text_area;
		}
		else if( strTmp == "data" || strTmp == "DATA" )
		{
			faultTmp.location = data_area;
		}
		else if( strTmp == "stack" || strTmp == "STACK" )
		{
			faultTmp.location = stack_area;
		}
		else
		{
			cerr << "Error:undefined fault location" << endl;
			return RT_FAIL;
		}
		
		/// memory addr: or random
		strTmp.clear();
		stream >> strTmp;
		if( strTmp.empty() )
		{
			cerr << "Error:fault table format errno" << endl;
			return RT_FAIL;
		}
		if( strTmp == "random" || strTmp == "RANDOM" )
		{
			faultTmp.addr = -1;
		}
		else
		{
			int iRet = sscanf( strTmp.c_str(), "%lx", &faultTmp.addr );
			if( iRet != 1 ) { return RT_FAIL; }
		}
			
		/// fault type: one_bit_flip, etc
		strTmp.clear();
		stream >> strTmp;
		if( strTmp.empty() )
		{
			cerr << "Error:fault table format errno" << endl;
			return RT_FAIL;
		}
		else if( strTmp == "one_bit_0" )
		{
			faultTmp.faultType = one_bit_0;
		}
		else if( strTmp == "one_bit_1" )
		{
			faultTmp.faultType = one_bit_1;
		}
		else if( strTmp == "one_bit_flip" )
		{
			faultTmp.faultType = one_bit_flip;
		}
		
		else if( strTmp == "word_0" )
		{
			faultTmp.faultType = word_0;
		}
		else if( strTmp == "page_0" )
		{
			faultTmp.faultType = page_0;
		}
/*		
		else if( strTmp == "two_bit_0" )
		{
			faultTmp.faultType = two_bit_0;
		}
		else if( strTmp == "two_bit_1" )
		{
			faultTmp.faultType = two_bit_1;
		}
		else if( strTmp == "two_bit_flip" )
		{
			faultTmp.faultType = two_bit_flip;
		}
		else if( strTmp == "low_8_0" )
		{
			faultTmp.faultType = low_8_0;
		}
		else if( strTmp == "low_8_1" )
		{
			faultTmp.faultType = low_8_1;
		}
		else if( strTmp == "low_8_error" )
		{
			faultTmp.faultType = low_8_error;
		}
		else if( strTmp == "word_0" )
		{
			faultTmp.faultType = word_0;
		}
		else if( strTmp == "word_1" )
		{
			faultTmp.faultType = word_1;
		}
		else if( strTmp == "word_error" )
		{
			faultTmp.faultType = word_error;
		}
		else if( strTmp == "page_0" )
		{
			faultTmp.faultType = page_0;
		}
		else if( strTmp == "page_1" )
		{
			faultTmp.faultType = page_1;
		}
		else if( strTmp == "page_error" )
		{
			faultTmp.faultType = page_error;
		}
*/		
		else
		{
			cerr << "Error:undefined fault type" << endl;
			return RT_FAIL;
		}
		
		/// how long fault exits, not support yet 
		strTmp.clear();
		stream >> strTmp;
		if( strTmp.empty() )
		{
			cerr << "Error:fault table format errno" << endl;
			return RT_FAIL;
		}
		faultTmp.time = atoi( strTmp.c_str() );
		
		/// timeout
		strTmp.clear();
		stream >> strTmp;
		if( strTmp.empty() )
		{
			cerr << "Error:fault table format errno" << endl;
			return RT_FAIL;
		}
		faultTmp.timeout = atoi( strTmp.c_str() );
		
		//add a fault into fault vector
		faultTable.push_back( faultTmp );
	}
	
	infile.close();
	return RT_OK;
}

int Injector::startInjection( void )
{
	int iRet;
	int data = 0;
	
	//inject fault into an existing process
	if( targetPid > 0 && exeArguments == NULL )
	{
		iRet = injectFaults( targetPid );
		if( iRet != RT_OK ) { return RT_FAIL; }
		return RT_OK;
	}
	if( targetPid > 10 && exeArguments == NULL )
	{
		//设置跟踪进程，等待子进程停止
		signalPid = targetPid;		//用于给sigAlrm函数传递进程号
		iRet = ptraceAttach( targetPid );
		if( iRet == RT_FAIL ) { return RT_FAIL; }
			
		do {
			iRet = procMonitor( targetPid,data );
			if( iRet == RT_FAIL ) { return RT_FAIL; }
		} while( iRet == RUN );
		
		//should be STOP
		if( iRet != STOP )
		{
			writeResult( targetPid, iRet, data );	//exit or term
			return RT_FAIL;
		}

		//进行故障注入
		iRet = injectFaults( targetPid );
		if( iRet != RT_OK ) { return RT_FAIL; }
		
		//继续执行
		ptraceCont( targetPid );
		
		//跟踪继续执行后的子进程
		while( 1 )
		{
			iRet = procMonitor( targetPid, data );
			if( iRet == RT_FAIL ) { return RT_FAIL; }
				
			if( iRet == RUN )
			{
				continue;
			}
			else if( iRet == STOP )
			{
				if( data == SIGTRAP ){ data = 0; }
				ptraceCont( targetPid, data );
			}
			else //exit or term
			{
				writeResult( targetPid, iRet, data );
				break;
			}
		}
		return RT_OK;
	}
	//inject fault into an excultable program
	if( exeArguments != NULL && targetPid < 0 )
	{
		errno = 0;
		pid_t child = fork();
		if( child < 0 )
		{
			perror("fork");
			return RT_FAIL;
		}
		else if( child == 0 )	/// child
		{
			startExe();
			_exit( RT_EXIT );
		}
		else	/// parent
		{
			childProcess = child;
			//inject fault into physical memory address
			iRet = injectFaults(child);
			if( iRet == RT_FAIL ) { cleanup(); }

			while(1)
			{
				iRet = procMonitor( child, data );
				if(iRet == RT_FAIL)
				{
					cleanup();
					return RT_FAIL;
				}
				if( iRet == RUN )
				{ 
					/// cout << "process " << child << " running" << endl;
					continue;
				}
				else if( iRet == STOP )
				{
					/// cout << "process " << child << "stopped" << endl;
					cleanup();
					break;
				}
				else /// exit or term
				{
					/// 写结果文件
					cleanup();
					writeResult( child, iRet, data );
					break;
				}
			}
			return RT_OK;
		}
	}

	cerr << "injection target is wrong" << endl;
	return RT_FAIL;
}

//RT_FAIL,进程已经结束
//RT_OK,进程没有结束
int Injector::injectFaults( int pid )
{
	int iRet;
	unsigned int i;
	taskMMInfo procInfo;
	long start_va, end_va;
	unsigned long random_offset;
	
	for( i=0; i<faultTable.size(); i++ )
	{
		/// location
		if( faultTable[i].addr == -1 )
		{
			/// get proc information
			bzero(&procInfo, sizeof(procInfo));
			iRet = getTaskInfo(pid, &procInfo);
			//debug add by fenggang
			/*
			printf("start_code\t\t%lx\n", procInfo.start_code);
			printf("end_code\t\t%lx\n", procInfo.end_code);
			printf("start_data\t\t%lx\n", procInfo.start_data);
			printf("end_data\t\t%lx\n", procInfo.end_data);
			printf("start_brk\t\t%lx\n", procInfo.start_brk);
			printf("brk\t\t\t%lx\n", procInfo.brk);
			printf("start_stack\t\t%lx\n", procInfo.start_stack);
			return 0;
			*/
			//debug
			if(iRet == FAIL)
			{
				cleanup();
				return RT_FAIL;
			}
			
			if( faultTable[i].location == text_area )
			{
				start_va = procInfo.start_code;
				end_va = procInfo.end_code;
			}
			else if( faultTable[i].location == data_area )
			{
				start_va = procInfo.start_data;
				end_va = procInfo.end_data;
			}
			else if( faultTable[i].location == stack_area )
			{
				start_va = procInfo.start_stack - STACK_SIZE;
				end_va = procInfo.start_stack;
			}

			/* add by fenggang
			printf("inject_va:\t%lx\n", start_va); //add by fenggang, 
			inject_pa = virt_to_phys(pid, start_va);
			printf("inject_pa:\t%lx\n", inject_pa); //add by fenggang, 

			printf("inject_va:\t%lx\n", end_va); //add by fenggang, 
			inject_pa = virt_to_phys(pid, end_va);
			printf("inject_pa:\t%lx\n", inject_pa); //add by fenggang, 

			srand( time( NULL ) );
			random_offset = rand() % (end_va - start_va);
			printf("inject_va:\t%lx\n", start_va + random_offset); //add by fenggang, 
			inject_pa = virt_to_phys(pid, start_va + random_offset);
			printf("inject_pa:\t%lx\n", inject_pa); //add by fenggang, 
			return 0;
			*/
			/// random addr
			srand( time( NULL ) );
			if(end_va == start_va)
				random_offset = 0;
			else
				random_offset = rand() % (end_va - start_va);
			//printf("inject_va:\t%lx\n", start_va + random_offset); //add by fenggang, 
			inject_pa = virt_to_phys(pid, start_va + random_offset);
			//printf("inject_pa:\t%lx\n", inject_pa); //add by fenggang, 
		}
		else
		{
			inject_pa = faultTable[i].addr;
		}
		
		if(inject_pa == -1) { return RT_FAIL; }
		
		printf("Inject fault at 0x%lx(physical:0x%lx)\n", start_va + random_offset, inject_pa);
		
		if(iRet == FAIL) { return RT_FAIL; }
		switch( faultTable[i].faultType )
		{
			case one_bit_0:
				iRet = read_phy_mem(inject_pa, &origData);
				if(iRet == FAIL) { return RT_FAIL; }
				srand( time( NULL ) );
				newData = origData & ( ~(0x0000000000000001L << (rand()%16)) );
				iRet = write_phy_mem(inject_pa, &newData, sizeof(newData));
				if(iRet == FAIL) { return RT_FAIL; }
				iRet = read_phy_mem(inject_pa, &newData);
				if(iRet == FAIL) { return RT_FAIL; }
				printf("one bit 0(0x%lx -> 0x%lx)\n", origData, newData);
				break;
			case one_bit_1:
				iRet = read_phy_mem(inject_pa, &origData);
				if(iRet == FAIL) { return RT_FAIL; }
				srand( time( NULL ) );
				newData = origData | (0x0000000000000001L << (rand()%16));
				iRet = write_phy_mem(inject_pa, &newData, sizeof(newData));
				if(iRet == FAIL) { return RT_FAIL; }
				iRet = read_phy_mem(inject_pa, &newData);
				if(iRet == FAIL) { return RT_FAIL; }
				printf("one bit 1(0x%lx -> 0x%lx)\n", origData, newData);
				break;
			case one_bit_flip:
				iRet = read_phy_mem(inject_pa, &origData);
				if(iRet == FAIL) { return RT_FAIL; }
				srand( time( NULL ) );
				newData = origData ^ (0x0000000000000001L << ( rand() % 16 ));
				iRet = write_phy_mem(inject_pa, &newData, sizeof(newData));
				if(iRet == FAIL) { return RT_FAIL; }
				iRet = read_phy_mem(inject_pa, &newData);
				if(iRet == FAIL) { return RT_FAIL; }
				printf("one bit flip(0x%lx -> 0x%lx)\n", origData, newData);
				break;
			case word_0:
				iRet = read_phy_mem(inject_pa, &origData);
				if(iRet == FAIL) { return RT_FAIL; }
				newData = 0;
				iRet = write_phy_mem(inject_pa, &newData, sizeof(newData));
				if(iRet == FAIL) { return RT_FAIL; }
				iRet = read_phy_mem(inject_pa, &newData);
				if(iRet == FAIL) { return RT_FAIL; }
				printf("word 0(0x%lx -> 0x%lx)\n", origData, newData);
				break;
			case page_0:
				iRet = write_page_0(inject_pa);
				if(iRet == FAIL) { return RT_FAIL; }
				printf("page 0\n");
				break;
			default:
				printf("Do not support yet.\n");
		}
		
		/// timeout to terminate child process
		timeout( faultTable[i].timeout, report );
		
	}
	return RT_OK;
}

//侦测进程状态
//返回值=RT_FAIL，函数失败
//返回值=RUN，进程没有停止或结束，正在执行或等待
//返回值=STOP，进程停止
//返回值=EXIT，进程正常退出,data为退出码
//返回值=TERM，进程异常终止，data为异常信号
int Injector::procMonitor( int pid, int &data )
{
	int iRet;
	int status;
	iRet = waitpid( pid, &status, WNOHANG | WCONTINUED );
	if( iRet == -1 ) 
	{ 
		perror( "waitpid" );
		return RT_FAIL;
	}
	else if( iRet == 0 ) 
	{
		return RUN;
	}
	else if(iRet == pid)
	{
		if( WIFSTOPPED( status ) )
		{
			data = WSTOPSIG( status );
			return STOP;
		}
		else if( WIFEXITED( status ) )
		{
			data = WEXITSTATUS( status );
			return EXIT;
		}
		else if( WIFSIGNALED( status ) )
		{
			data = WTERMSIG( status );
			return TERM;
		}
		else
		{
			return RT_FAIL;
		}
	}
	else
	{
		return RT_FAIL;
	}
}

char * Injector::nameSignal( int signo )
{
	if( signo >= SIGRTMIN && signo <= SIGRTMAX )
	{
		return "reliable signal";
	}
	switch( signo )
	{
		case 1:
			return "SIGHUP";
		case 2:
			return "SIGINT";
		case 3:
			return "SIGQUIT";
		case 4:
			return "SIGILL";
		case 5:
			return "SIGTRAP";
		case 6:
			return "SIGABRT";	//or "SIGIOT"
		case 7:
			return "SIGBUS";
		case 8:
			return "SIGFPE";
		case 9:
			return "SIGKILL";
		case 10:
			return "SIGUSR1";
		case 11:
			return "SIGSEGV";
		case 12:
			return "SIGUSR2";
		case 13:
			return "SIGPIPE";
		case 14:
			return "SIGALRM";
		case 15:
			return "SIGTERM";
		case 16:
			return "SIGSTKFLT";
		case 17:
			return "SIGCHLD";
		case 18:
			return "SIGCONT";
		case 19:
			return "SIGSTOP";
		case 20:
			return "SIGTSTP";
		case 21:
			return "SIGTTIN";
		case 22:
			return "SIGTTOU";
		case 23:
			return "SIGURG";
		case 24:
			return "SIGXCPU";
		case 25:
			return "SIGXFSZ";
		case 26:
			return "SIGVTALRM";
		case 27:
			return "SIGPROF";
		case 28:
			return "SIGWINCH";
		case 29:
			return "SIGIO"; 	// or "SIGPOLL"
		case 30:
			return "SIGPWR";
		case 31:
			return "SIGSYS";
		default:
			cerr << "unknown signal" << endl;
			return "unknown";
	}
}

void Injector::startExe()
{
	int fd;
	if((fd = open("/dev/null", O_RDWR)) == -1)
	{
		perror("open");
		_exit(RT_FAIL);
	}
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);
	close(fd);
	execv( exeArguments[0], exeArguments );
}

void Injector::usage()
{
	printf("Usage:\n");
	printf("\t./memInjector -c fault.conf -e program [arguments]\n");
	printf("\t./memInjector -c fault.conf -p pid\n");
	printf("Arguments:\n");
	printf("\t1.fault description scripts.\n");
	printf("\t2.workload, workload can be a executable program or a running process ID.\n");
}

void Injector::writeResult( int pid, int status, int data )
{
	time_t localTime = time( NULL );
	tm lt = *localtime( &localTime );
	stringstream timeStamp;
	timeStamp << 1900 + lt.tm_year << "-" << 1 + lt.tm_mon << "-"	<< lt.tm_mday << " ";
	timeStamp << lt.tm_hour << ":" <<	lt.tm_min << ":" << lt.tm_sec;		//2009-10-23 16:23:12
			
	if( status == EXIT )
	{
		cout   << '[' << setw(19) << timeStamp.str() << ']' << "Process " << pid << " exited with code " << data << endl;
	}
	else if( status == TERM )
	{
		cout 	 << '[' << setw(19) << timeStamp.str() << ']' << "Process " << pid << " termed with signal " << data << "(" << nameSignal( data ) << ")"<< endl;
	}
}

void Injector::cleanup(void)
{
	int iRet = kill(childProcess, 0);
	if(iRet != -1)
	{
		iRet = kill(childProcess, SIGTERM);
		if(iRet < 0)
		{
			perror("kill");
			exit(RT_EXIT);
		}
	}
}

void Injector::report(int signo)
{
	int iRet;
	printf("%d timeout\n", childProcess);
	cleanup();
	iRet = write_phy_mem(inject_pa, &origData, sizeof(origData));
}
/*
void Injector::restore(int signo)
{
	int iRet;
	cout << "restore" << endl;
	iRet = write_phy_mem(inject_pa, &origData, sizeof(origData));
	kill(childProcess, SIGALRM);
}
*/
void Injector::timeout(int sec, void(*func)(int))
{
	signal(SIGALRM, func);
	alarm(sec);
}
