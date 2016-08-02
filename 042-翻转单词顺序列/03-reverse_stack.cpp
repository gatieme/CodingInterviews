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


//使用两个栈
class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str.size( ) == 0)
        {
            return str;
        }

        string          result;
        stack<char>     stk1;
        stack<char>     stk2;

        for (auto i : str)
        {   //把str中的全部压入
            debug <<"push in stack_1 "<<i <<endl;
            stk1.push(i);
        }

        //  通过将字符串压入栈中, 现在出栈顺序正好是入栈顺序的逆序
        //  即我们实现了一次整个字符串的翻转

        //  接下来我们翻转每个单词
        //  只要不是空格就一直入栈(实现翻转)
        //  遇见空格的时候，就读取栈中元素(出栈的顺序正好是每个单词的顺序)
        while (stk1.empty( ) != true)
        {
            if (stk1.top() != ' ')
            {   //没有遇到空格 就再弹出 压到第二个栈
                stk2.push(stk1.top());
                debug <<"pop stack_1, and push in stack_2 " <<stk1.top( ) <<endl;
                stk1.pop( );
            }
            else
            {   //如果遇到了空格 一个单词结束了  将第二个栈里的弹出
                while (stk2.empty( ) != true)
                {
                    result += stk2.top();

                    debug <<"pop form stack_2 " <<stk2.top( ) <<endl;
                    stk2.pop();
                }
                result += stk1.top();//空格也要加上
                stk1.pop();//不要忘记！！！
            }
        }
        while (!stk2.empty()) {//此时stk1已经空了 上面的循环进不去了 但是stk2中还有最后一个单词！！！！注意！！！
            result += stk2.top();
            stk2.pop();
        }
        return result;
    }
};

int __tmain( )
{
    Solution solu;
    cout <<solu.ReverseSentence("student. a am I") <<endl;

    return 0;
}
