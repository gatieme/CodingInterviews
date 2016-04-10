#include <iostream>
#include <stack>
using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution
{
public:
    void push(int node)
    {
        stackIn.push(node);
    }

    int pop()
    {
        int node = -1;

        //  两个栈都是NULL的时候，整个队列为空
        if(this->empty( ) == true)
        {
            debug <<"整个队列为NULL" <<endl;

            return -1;
        }
        else
        {
            //  否则队列中有元素
            //  此时分两种情况，
            //  当输出栈不为空的时候, 直接将输出栈中元素弹出即可
            //  当输出栈为NULL, 但是输入栈不为空的时候，需要将输入栈的元素全部倒入输出栈中

            if(stackOut.empty() == true)     //  此时输出栈为空, 输入栈必不为空
            {
                //  此时缓冲栈（输出栈）中没有元素
                //  需要将输入栈中的元素倒入输出栈
                // 看输入栈中有没有元素

                //  否则将元素从输入栈导入输出栈
                while(stackIn.empty( ) != true)
                {
                    node = stackIn.top( );
                    stackIn.pop( );
                    stackOut.push(node);
                    debug <<node <<"导入输出栈" <<endl;
                }
            }

            node = stackOut.top( );
            stackOut.pop( );

            debug <<"队头元素" <<node <<endl;
        }

        return node;
    }

    bool empty( )
    {
        return (stackIn.empty() == true && stackOut.empty() == true);
    }

private:
    stack<int> stackIn;
    stack<int> stackOut;
};


int __tmain( )
{
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);

    int node;
    while(solu.empty() != true)
    {

        cout <<solu.pop( );
    }

    return 0;
}
