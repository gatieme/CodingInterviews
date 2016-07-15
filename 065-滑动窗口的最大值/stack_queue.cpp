#include <iostream>
#include <vector>
#include <iterator>

#include <climits>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#define MAX 100

class Stack
{
private:
    int stackItem[MAX];
    int link2NextMaxValueIndex[MAX];
    int stackTop;
    int maxValueIndex;
public:
    Stack() : stackTop(-1), maxValueIndex(-1) {}
    int size() { return stackTop + 1; }
    int empty() { return stackTop < 0 ? 1 : 0; }

    void push(int val)
    {
        ++stackTop;
        if(stackTop == MAX)
        {
            cout << "The stack has been full!" << endl;
            return;
        }
        else
        {
            stackItem[stackTop] = val;
            if(max() < val)
            {
                link2NextMaxValueIndex[stackTop] = maxValueIndex;
                maxValueIndex = stackTop;
            }
            else
                link2NextMaxValueIndex[stackTop] = -1;
        }
    }

    int pop()
    {
        int ret;
        if(stackTop == -1)
        {
            cout << "The stack is empty!" << endl;
            return -1;
        }
        else
        {
            ret = stackItem[stackTop];
            if(stackTop == maxValueIndex)
            {
                maxValueIndex = link2NextMaxValueIndex[stackTop];
            }
            --stackTop;

            return ret;
        }
    }

    int max()
    {
        if(maxValueIndex >= 0)
            return stackItem[maxValueIndex];
        else
            return -100;
    }

};
class Queue
{
private:
    Stack stackIn;
    Stack stackOut;
public:
    int size( )
    {
        return stackIn.size( ) + stackOut.size( );
    }
    int max( )
    {
        return std::max(stackIn.max( ), stackOut.max( ));
    }

    void enQueue(int val)
    {
        stackIn.push(val);
    }

    int deQueue()
    {
        if(stackOut.empty() and !stackIn.empty())
        {
            while(!stackIn.empty())
                stackOut.push(stackIn.pop());
        }
        return stackOut.pop();
    }
};

class Solution
{
public      :
   vector<int> maxInWindows(const vector<int>& num, unsigned int size)
   {
        unsigned int    length = num.size( );
        vector<int>     res;

        if(length == 0 || size == 0 || length < size)
        {
            return res;
        }

        Queue           que;
        for(int i = 0; i < num.size( ); i++)
        {
            if(que.size( ) < size)
            {
                que.enQueue(num[i]);
            }
            else
            {
                res.push_back(que.max( ));

                que.enQueue(num[i]);
                que.deQueue( );
            }
        }
        if(que.size( ) == size)
        {
            res.push_back(que.max( ));
        }

        return res;
    }


};

int __tmain()
{
    Solution solu;

    int array[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    vector<int> vec(array, array + 8);

    vector<int> res = solu.maxInWindows(vec, 3);
    copy(res.begin( ), res.end( ), ostream_iterator<int>(cout," "));

    return 0;
}
