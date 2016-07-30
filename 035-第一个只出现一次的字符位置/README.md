#链接
-------
>牛客OJ：[第一个只出现一次的字符位置](http://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
>
>九度OJ：http://ac.jobdu.com/problem.php?pid=1283
>
>GitHub代码： [035-第一个只出现一次的字符位置](https://github.com/gatieme/CodingInterviews/tree/master/035-第一个只出现一次的字符位置)
>
>CSDN题解：[剑指Offer--035-第一个只出现一次的字符位置](http://blog.csdn.net/gatieme/article/details/51319158)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------ |:------:| --------:|:----------:|
|[035-第一个只出现一次的字符位置](http://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | [1283-第一个只出现一次的字符位置](http://ac.jobdu.com/problem.php?pid=1283) | [剑指Offer--035-第一个只出现一次的字符位置](http://blog.csdn.net/gatieme/article/details/51319158) | [035-第一个只出现一次的字符位置](https://github.com/gatieme/CodingInterviews/tree/master/035-第一个只出现一次的字符位置) |




<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**





#题意
-------

**题目描述**

在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。若为空串，返回-1。位置索引从0开始


#暴力方法
-------

最简单直接的方法就是对于每一个字符，循环判断后面的字符是不是跟它相同，直到查找到第一个只出现一次的那个字符即可

```cpp
class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        if(str.length( ) == 0)
        {
            return -1;
        }
        unsigned int length = str.length( );
        unsigned int i, j;
        bool flag = true;
        for(i = 0; i < length; i++)
        {
            flag = true;
            if(str[i] == '\0')
            {
                continue;
            }
            debug <<"str[" <<setfill('0')<<setw(2)<<i <<"] = " <<str[i] <<endl;

            for(j = i + 1; j < length; j++)
            {
                debug <<"str[" <<i <<"] = " <<str[i] <<", ";
                debug <<"str[" <<j <<"] = " <<str[j] <<endl;;

                if(str[j] == '\0')
                {
                    continue;
                }
                else if(str[i] == str[j])
                {
                    debug <<str[i] <<str[j] <<endl;
                    str[j] = '\0';
                    flag = false;
                    //break;
                }

            }
            if(flag == true)
            {
                return i;
            }
        }
        return -1;
    }
};
```


#计数法
-------

我们还有一种方法就是统计每个字符串的出现的次数，然后查找第一个只出现一次的字符位置

```cpp
class Solution
{
protected:
    int count[256];
public:
    int FirstNotRepeatingChar(string str)
    {
        if(str.length( ) == 0)
        {
            return -1;
        }
        unsigned int i;
        //  将计数器数组清0
        memset(count, '\0', sizeof(count));

        //  对字符串中出现的每个字符进行计数
        for(i = 0; i < str.length( ); i++)
        {
            debug <<(unsigned int)str[i] <<endl;
            count[(unsigned int)str[i]]++;
        }


        //  第一个只出现一次的字符
        for(i = 0; i < str.length( ); i++)
        {
            debug <<str[i] <<", " <<count[(unsigned
                 int)str[i]] <<endl;
            if(count[(unsigned int)str[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};
```


#bitmap方法-同计数法，略微有变动
-------

我们计数数组不简单的存储计数
* 只出现一次的字符会存储出现的位置
* 出现多次的字符就存储标识-1
因此查找数组中非-1的最小值即可



```cpp
class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        int x[26] = {0}, y[26] = {0};

        for(unsigned int i = 0; i < str.size(); ++i)
        {
            //  小写字母
            if('a' <= str[i] && str[i] <= 'z')
            {
                if(x[str[i] - 'a'] == 0)
                {
                    //  首次出现保存出现位置
                    x[str[i] - 'a'] = i + 1;
                }
                else
                {
                    //  出现多次, 就置标识-1
                    x[str[i] - 'a'] = -1;
                }
                debug <<str[i] <<", " <<x[str[i] - 'a'] <<endl;
            }
            else if('A' <= str[i] && str[i] <= 'Z')      // 大写字母
            {
                if(y[str[i] - 'A'] == 0)
                {
                     //  首次出现保存出现位置
                     y[str[i] - 'A']= i + 1;
                }
                else
                {
                    //  出现多次, 就置标识-1
                    y[str[i] - 'A'] = -1;
                }
                debug <<str[i] <<", " <<y[str[i] - 'A'] <<endl;

            }
        }

        //  由于标识数组中
        //  只出现一次的字符会存储出现的位置
        //  出现多次的字符就存储标识-1
        //  因此查找数组中非-1的最小值即可
        int res = INT_MAX;
        for(int i = 0; i < 26; ++i)
        {
            if(x[i] != 0 && x[i] != -1)
            {
                res = min(res, x[i]);
            }
            if(y[i] != 0 && y[i] != -1)
            {
                res = min(res, y[i]);
            }
        }
        return res > str.size() ? -1 : res - 1;
    }
};
```
