/* 
 * Question Description:
 * (Question 30 in <Coding Intervies>) How do you implement a function to check whether there is a 
 * path for a string in a matrix of characters? It moves to left, right, up, and down in a matrix, 
 * and a cell for a step. The path can start from any cell in a matrix. If a cell is occupied by a 
 * character of a string on the path, it cannot be occupied by another character again. 
 */

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited);

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
        return false;

    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int pathLength = 0;
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            if(hasPathCore(matrix, rows, cols, row, col, str, 
                pathLength, visited))
            {
                return true;
            }
        }
    }
    
    delete[] visited;

    return false;
}

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')
        return true;
        
    bool hasPath = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols 
            && matrix[row * cols + col] == str[pathLength]
            && !visited[row * cols + col])
    {
        ++pathLength;
        visited[row * cols + col] = true;
        
        hasPath = hasPathCore(matrix, rows, cols, row, col - 1, 
                    str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row - 1, col, 
                    str, pathLength, visited)
                || hasPathCore(matrix, rows, cols, row, col + 1, 
                    str, pathLength, visited) 
                || hasPathCore(matrix, rows, cols, row + 1, col, 
                    str, pathLength, visited);
        
        if(!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }
    
    return hasPath;
}

void Test(char* testName, char* matrix, int rows, int cols, char* str, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABCE
//SFCS
//ADEE

//ABCCED
void Test1()
{
    char matrix[] = "ABCESFCSADEE";
    char* str = "ABCCED";

    Test("Test1", (char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    char matrix[] = "ABCESFCSADEE";
    char* str = "SEE";

    Test("Test2", (char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//ABCB
void Test3()
{
    char matrix[] = "ABCESFCSADEE";
    char* str = "ABCB";

    Test("Test3", (char*)matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (char*)matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (char*)matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    char matrix[] = "AAAAAAAAAAAA";
    char* str = "AAAAAAAAAAAA";

    Test("Test8", (char*)matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    char matrix[] = "AAAAAAAAAAAA";
    char* str = "AAAAAAAAAAAAA";

    Test("Test9", (char*)matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    char matrix[] = "A";
    char* str = "A";

    Test("Test10", (char*)matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    char matrix[] = "A";
    char* str = "B";

    Test("Test11", (char*)matrix, 1, 1, str, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();

	return 0;
}