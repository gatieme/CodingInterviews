#链接
------- 
>牛客OJ：[正则表达式匹配](http://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [053-正则表达式匹配](https://github.com/gatieme/CodingInterviews/tree/master/053-正则表达式匹配)
>
>CSDN题解：[剑指Offer--053-正则表达式匹配](http://blog.csdn.net/gatieme/article/details/51542072)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[053-正则表达式匹配](http://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | 未收录 | [剑指Offer--053-正则表达式匹配](http://blog.csdn.net/gatieme/article/details/51542072) | [053-正则表达式匹配](https://github.com/gatieme/CodingInterviews/tree/master/053-正则表达式匹配) |



>同样的题目
>
>[LeetCode题解--10. Regular Expression Matching](http://blog.csdn.net/gatieme/article/details/51049244)



#题意
-------

**题目描述**

>请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

**样例输入**

>"a","ab*a"

**样例输出**

>false






#分治–类似与深度优先搜索DFS

-------
我们会分治搜索的方法来查看，

*    考虑特殊情况即*s字符串或者*p字符串结束。

1.    s字符串结束，要求*p也结束或者间隔‘’ （例如p=”a*b*c……”），否则无法匹配

2.    *s字符串未结束，而*p字符串结束，则无法匹配



*    *s字符串与*p字符串均未结束



1.    (p+1)字符不为’‘，则只需比较s字符与*p字符，若相等则递归到(s+1)字符串与*(p+1)字符串的比较，否则无法匹配。



2.    (p+1)字符为’‘，则p字符可以匹配*s字符串中从0开始任意多（记为i）等于*p的字符，然后递归到(s+i+1)字符串与*(p+2)字符串的比较，

只要匹配一种情况就算完全匹配。



```cpp

///if      p[j+1] == '*' -> (i + 1, j + 1)
///else if p[i] == p[j] -> (i + 1, j + 2) or (i, j+2)
///else -> (i, j+2)

class Solution
{
public:
    bool match(const char *s, const char *p)
    {
        if (*p == '\0')         //  正则p到底末尾时
        {
            return !(*s);       //  如果串s页到达末尾，则匹配成功
        }

        int slen = strlen(s), plen = strlen(p);

        if (plen == 1           //  如果正则串只有一个长度
        || *(p + 1) != '*')     //  如果匹配*
        {
            //
            return slen && (p[0] == '.' || *s == *p)
                && match(s + 1, p + 1);
        }
        else
        {
            //  匹配一个字符
            while (*s != '\0' && (*p == '.' || *s == *p))
            {
                if (match(s++, p + 2))
                {
                    return true;
                }
            }
        }

        //  匹配0个字符
        return match(s, p + 2);
    }
};
```





#动态规划
-------



dp[i][j] 表示 s[0..i] 和 p[0..j] 是否 match，



*    当 p[j] != ‘*’，b[i + 1][j + 1] = b[i][j] && s[i] == p[j] ，



*    当 p[j] == ‘*’ 要再分类讨论，具体可以参考 DP C++，还可以压缩下把 dp 降成一维：

下面是那位大神的代码

```cpp
class Solution
{
public:
    bool match(string s, string p) {
        /**
         * f[i][j]: if s[0..i-1] matches p[0..j-1]
         * if p[j - 1] != '*'
         *      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
         * if p[j - 1] == '*', denote p[j - 2] with x
         *      f[i][j] is true iff any of the following is true
         *      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
         *      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
         * '.' matches any single character
         */
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

        f[0][0] = true;
        for (int i = 1; i <= m; i++)
            f[i][0] = false;
        // p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] != '*')
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                else
                    // p[0] cannot be '*' so no need to check "j > 1" here
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

        return f[m][n];
    }
};
```