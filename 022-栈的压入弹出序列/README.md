#链接
-------
>牛客OJ：[栈的压入、弹出序列](http://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1366
>
>GitHub代码： [022-栈的压入弹出序列](https://github.com/gatieme/CodingInterviews/tree/master/022-栈的压入弹出序列)
>
>CSDN题解：[剑指Offer--022栈的压入、弹出序列](http://blog.csdn.net/gatieme/article/details/51190653)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------------- |:-------------:| -----:| -------:|
|[栈的压入、弹出序列](http://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1366-栈的压入、弹出序列](http://ac.jobdu.com/problem.php?pid=1366) | [剑指Offer--022栈的压入、弹出序列](http://blog.csdn.net/gatieme/article/details/51190653) | [022-栈的压入弹出序列](https://github.com/gatieme/CodingInterviews/tree/master/022-栈的压入弹出序列) |



<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**


#题意
-------


**题目描述**


>输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。

假设压入栈的所有数字均不相等。

例如序列1,2,3,4,5是某栈的压入顺序，

序列4，5,3,2,1是该压栈序列对应的一个弹出序列，

但4,3,5,1,2就不可能是该压栈序列的弹出序列。

#分析
-------

http://www.cnblogs.com/kaituorensheng/p/3618339.html
http://blog.csdn.net/htyurencaotang/article/details/9266157
http://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106
http://www.cnblogs.com/tgkx1054/archive/2012/11/13/2769014.html

#辅助栈模拟入栈出栈过程
-------
思路：



开辟一个辅助栈，模拟入栈出战过程(假设pa为入栈序列，pb为出战序列)

pa中的元素依次压入辅助栈

新压入的元素与弹出序列的栈底相同，辅助栈弹出，同时pb向上移动

不相同了pa中的元素继续入辅助



*    如果下一个弹出的数字刚好是栈顶数字，则直接弹出。


*    若下一个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止。

*    若所有的数字都压入栈了仍没有找到下一个弹出的数字，则表明该序列不可能滴一个弹出序列。

```cpp
#include <iostream>
#include <stack>
#include <vector>

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
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {

        if(pushV.size( ) == 0 || popV.size( ) == 0)
        {
            return false;
        }
        stack<int> s;
        int push, pop;

        s.push(pushV[0]);
        debug <<"push" <<pushV[0] <<endl;

        for(push = 0, pop = 0;
            push < pushV.size() && pop < popV.size( );)
        {
            if(s.empty( ) != true && s.top( ) == popV[pop])        //  当前栈顶元素正好是出栈序列中的元素
            {
                debug <<"pop"<<popV[pop] <<endl;
                // 模拟出栈的过程
                s.pop( );
                pop++;
            }
            else
            {

                //  模拟入栈的过程
                s.push(pushV[++push]);
                debug <<"push" <<pushV[push] <<endl;

            }
        }
        if(s.empty( ) == true)
        {
            return true;
        }
        else
        {
            return false;
        }




    }
};

int __tmain( )
{
	int nPush[5] = {1,2,3,4,5};
	int nPop1[5] = {4,5,3,2,1};
	int nPop2[5] = {4,3,5,1,2};
    int nPop3[5] = {5,4,3,2,1};
	int nPop4[5] = {4,5,2,3,1};

	Solution solu;

	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop1, nPop1 + 5)) << endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop2, nPop2 + 5)) << endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop3, nPop3 + 5)) << endl;
	cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop4, nPop4 + 5)) << endl;

	return 0;
}
```

我们这里用了一个辅助栈来模拟出栈入栈的过程，思路很简单很清晰，但是又没有可以优化的地方么

#用PushV入栈序列作为辅助栈
-------

其实由于当前栈的动作是肯定超不出pushV序列的，因此我们可以直接用PushV入栈序列作为我们的模拟栈，而用top去维护入栈出栈的操作

这种方法时间复杂度$O(n)$，空间复杂度$O(1)$，但是要修改输入参数PushV的值
```cpp

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        if(pushV.size( ) == 0 || popV.size( ) == 0)
        {
            return false;
        }
        int top = -1, push = 0, pop = 0;

        ++top;
        debug <<"push" <<pushV[top] <<endl;


        while(push < pushV.size() && pop < popV.size( ))
        {
            if(top != -1 && pushV[top] == popV[pop])        //  当前栈顶元素正好是出栈序列中的元素
            {
                debug <<"pop"<<popV[pop] <<endl;
                // 模拟出栈的过程
                top--;
                pop++;
            }
            else
            {

                //  模拟入栈的过程
                pushV[++top] = pushV[++push];
                debug <<"push" <<pushV[push] <<endl;

            }
        }
        debug <<top <<push <<pop <<endl;
        return (top == -1);
    }
};
```

或者直接使用
```cpp
class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {
        if(pushV.empty( ) || popV.empty( ) || pushV.size( )!= popV.size( ))
        {
            return false;
        }

        for(int i = 0;i < pushV.size();)
        {
            if(pushV[i] == popV[0])
            {
                pushV.erase(pushV.begin( ) + i);
                popV.erase(popV.begin( ));
                i--;                                // 模拟出栈
            }
            else
            {
                i++;                                //  模拟入栈
            }
        }

        return pushV.empty( );
    }

};
```

#发现规律
-------
这个是看到的别人的做法

不一样的思路：

1.    我先取出pop序列的第一个（比如pop【3,2,4,5,1】），在push序列中找到这个位置，push【1,2,3,4,5】，

2.    此时我们找到了3的位置.那么下一个pop的数字（此时的数字是2）必然是，push中3的前一个数字，或者后面的数字。否则返回False
如此循环直到最后，判断长度相等，就是弹出序列。否则返回False.
```py

# -*- coding:utf-8-*-

classSolution:

    def IsPopOrder(self, pushV, popV):

        # write code here

        iflen(pushV) != len(popV):

            returnFalse

        elif len(pushV) ==0:

            returnFalse

        x = popV[0]

        ifx not in pushV:

            returnFalse

        fori in range(len(popV)):

            position = pushV.index(popV[i])

            iflen(pushV) ==1:

                ifpushV[0] == popV[i]:

                    returnTrue

            try:

                ifpopV[i+1] == pushV[position-1]:

                    pushV.remove(pushV[position])

                elif popV[i+1] in pushV[position:]:

                    pushV.remove(pushV[position])

                else:

                    returnFalse

            except IndexError:

                returnFalse

        else:

            returnTrue


```

