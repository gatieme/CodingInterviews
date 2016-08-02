#链接
-------
>牛客OJ：[翻转单词顺序列](http://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1361
>
>GitHub代码： [042-翻转单词顺序列](https://github.com/gatieme/CodingInterviews/tree/master/042-翻转单词顺序列)
>
>CSDN题解：[剑指Offer--042-翻转单词顺序列](http://blog.csdn.net/gatieme/article/details/51419097)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:| ----------:|
|[042-翻转单词顺序列](http://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1361-翻转单词顺序列](http://ac.jobdu.com/problem.php?pid=1361) | [剑指Offer--042-翻转单词顺序列](http://blog.csdn.net/gatieme/article/details/51419097) | [042-翻转单词顺序列](https://github.com/gatieme/CodingInterviews/tree/master/042-翻转单词顺序列) |



<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#题意
-------

**题目描述**

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

**样例输入**

>student. a am I
>
>I'm a Freshman and I like JOBDU!

**样例输出**

>I am a student.
>
>JOBDU! like I and Freshman a I'm


#先翻转所有字符，再逐个单词翻转
-------

这道题主要思想就是先翻转所有字符，再逐个单词翻转

然后是如何查找到每个单词，用指针left和right维护单词的起始位置和结束位置

如果当前遇到一个空格，说明发现了一个单词

如果找到了单词的最后，而末尾字符不是空格，说明字符串的末尾也是一个单词

##通过翻转函数来实现
-------

```cpp
#include <iostream>

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
    string ReverseSentence(string str)
    {
        if(str.size( ) == 0)
        {
            return "";
        }

        //  首先翻转整个句子
        Reverse(str, 0, str.size( ) - 1);

        //  紧接着查找到每个单词, 然后翻转它
        int left = 0, right = 0;
        while(right <= str.size( ))
        {
            //  当遇见空格的时候说明找到了一个单词
            //  当走到字符串的最后一个位置, 那么前面如果不是空格, 那么最后也会有一个单词
            if((str[right] == ' ')
            || (right == str.size( ) && str[right - 1] != ' '))
            {
                /*
                for(int i = left; i < right; i++)
                {
                    debug <<str[i];
                }
                debug <<endl;
                */

                Reverse(str, left, right - 1);

                left = right + 1;
            }
            right++;
        }

        return str;
    }

    void Reverse(string &str, int left, int right)
    {
        while(left < right)
        {
            swap(str[left], str[right]);

            left++;
            right--;
        }
    }

    void Reverse(string::iterator left, string::iterator right)
    {
        while(left < right)
        {
            debug <<*left <<", " <<*right <<endl;
            swap(*left, *right);

            left++;
            right--;
        }
    }
};


int __tmain( )
{
    Solution solu;
    cout <<solu.ReverseSentence("student. a am I") <<endl;

    return 0;
}

```

##使用STL的函数库来实现
-------

也可以使用STL来实现这些功能

```cpp
class Solution
{
public:

    string ReverseSentence(string str)
    {
        if (str.size( ) == 0)
        {
            return str;
        }

        reverse(str.begin(), str.end());

        size_t left = 0;
        size_t right = 0;
        while(right != string::npos)
        {
            left = str.find_first_not_of(' ', left);  //  第一个非空格字符是单词的起始位置
            right = str.find_first_of(' ', left);      //  第一个空格位置标识了单词的结束

            //  处理末尾是空格(原字符串开头是空格的情况)
            //  当最后全是空格的时候，此时可以结束循环
            if (left == string::npos)
            {
                break;
            }
            //  如果查找不到空格, 到了字符串的末尾
            //  此时[degin, str.size( )]是末尾的字符串
            if (right == string::npos)
            {
                reverse(str.begin( ) + left, str.end( ));
            }
            else        //  否则[left, end]是一个单词
            {
                reverse(str.begin( ) + left, str.begin() + right);
                left = right + 1;
            }
        }

        return str;
    }
};
```

##用栈的后进先出特性实现翻转
-------

当然由于栈是后进先出的，因此我们可以通过栈来实现翻转

*    将每个字符依次入栈，那么出现的顺序正好就是逆序

```cpp
//使用两个栈
class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str.size() == 0)
        {
            return str;
        }

        string result;
        stack<char>stk1;
        stack<char>stk2;

        for (auto i : str)
        {//把str中的全部压入
            debug <<i <<endl;
            //stk1.push(i);
        }
        //  通过将字符串压入栈中, 现在出栈顺序正好是入展顺序的逆序
        //  即我们实现了一次整个字符串的翻转

        //  接下来我们翻转每个单词
        //  只要不是空格就一直入栈(实现翻转)
        //  遇见空格的时候，就读取栈中元素(出栈的顺序正好是每个单词的顺序)
        while (!stk1.empty())
        {
            if (stk1.top() != ' ')
            {   //没有遇到空格 就再弹出 压到第二个栈
                stk2.push(stk1.top());
                //debug <<stk1.top( );
                stk1.pop();
            }
            else
            {   //如果遇到了空格 一个单词结束了  将第二个栈里的弹出
                while (!stk2.empty())
                {
                    result += stk2.top();
                    debug <<stk2.top( );
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
```

#从后向前重新组装字符串
-------

>student. a am I
>
>I am a student.

还有以一种思路就是从后向前，读取到每个单词，就开始顺序的拼接它们

```cpp
class Solution
{
public:
    string ReverseSentence(string str)
    {
        string result;
        while (str.rfind(" ") != -1)
        {
            unsigned long position = str.rfind(" ");
            string temp = str.substr(position + 1);
            //debug <<temp <<endl;
            result = result + temp + ' ';
            str = str.substr(0, position);
            debug <<"str = " <<str <<endl;
        }
        //debug <<str <<endl;
        result = result + str;

        return result;
    }
};
```


或者
```cpp
class Solution
{
public:
    string ReverseSentence(string str)
    {
        if(str.size( ) == 0)
        {
            return str;
        }
        string res = "", tmp = "";
        for(unsigned int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ')       //  发现一个单词
            {
                debug <<tmp <<endl;
                res = " " + tmp + res;      //  顺序的拼接, 前面需要一个空格
                tmp = "";
            }
            else
            {
                tmp += str[i];
            }
        }
        if(tmp.size() != 0)     //  拼接最后一个单子, 前面无需空格
        {
            res = tmp + res;
        }
        return res;
    }
};
```
