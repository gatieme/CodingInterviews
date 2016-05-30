#链接
-------

LeetCode题目：https://leetcode.com/problems/regular-expression-matching/

GitHub代码：https://github.com/gatieme/LeetCode

CSDN题解：http://blog.csdn.net/gatieme/article/details/51049244



#题意
-------
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)
```
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
```

正则表达式匹配，
用`.` 匹配任何一个简单字符
用`*`可以匹配零个或者多个任意字符
判断给定的两个字符是否匹配

#分析
-------

*	偷懒的方法是直接用语言自带的正则实现。(Python 又是一句话 =w=)

*	用 DFS 的方法

*	可以用 DP 的方法

用数组 DP :dp[i][j] 表示 s[0..i] 和 p[0..j] 是否 match，当 p[j] != '*'，b[i + 1][j + 1] = b[i][j] && s[i] == p[j] ，当 p[j] == '*' 要再分类讨论，具体可以参考 DP C++，还可以压缩下把 dp 降成一维：参考这里
用记忆化，就是把算过的结果保存下来，下次就不用再算了

#Python
-------
```py
import re

class Solution:
    # @return a boolean
    def isMatch(self, s, p):
        return re.match('^' + p + '$', s) != None

# debug
s = Solution()
print s.isMatch("aa", "a*")
```
#分治--类似与深度优先搜索DFS
-------

我们会分治搜索的方法来查看，

*	考虑特殊情况即*s字符串或者*p字符串结束。

1.	*s字符串结束，要求*p也结束或者间隔‘*’ （例如*p="a*b*c*……"），否则无法匹配

2.	*s字符串未结束，而*p字符串结束，则无法匹配


*	*s字符串与*p字符串均未结束

1.	*(p+1)字符不为'*'，则只需比较*s字符与*p字符，若相等则递归到*(s+1)字符串与*(p+1)字符串的比较，否则无法匹配。

2.	*(p+1)字符为'*'，则*p字符可以匹配*s字符串中从0开始任意多（记为i）等于*p的字符，然后递归到*(s+i+1)字符串与*(p+2)字符串的比较，

只要匹配一种情况就算完全匹配。

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



#define __tmain main

///if      p[j+1] == '*' -> (i + 1, j + 1)
///else if p[i] == p[j] -> (i + 1, j + 2) or (i, j+2)
///else -> (i, j+2)

bool isMatch(const char *s, const char *p)
{
    if (*p == '\0')         //  正则p到底末尾时
    {
        return !(*s);       //  如果串s页到达末尾，则匹配成功
    }

    int slen = strlen(s), plen = strlen(p);

    if (plen == 1           //  如果正则串只有一个长度
    || *(p + 1) != '*')     //  如果匹配×
    {
        return slen && (p[0] == '.' || *s == *p)
            && isMatch(s + 1, p + 1);
    }
    else
    {
        while (*s != '\0' && (*p == '.' || *s == *p))
        {

            if (isMatch(s++, p + 2))
            {
                return true;
            }
        }

    }

    return isMatch(s, p + 2);

}



```


#动态规划
-------

dp[i][j] 表示 s[0..i] 和 p[0..j] 是否 match，

*	当 p[j] != '*'，b[i + 1][j + 1] = b[i][j] && s[i] == p[j] ，

*	当 p[j] == '*' 要再分类讨论，具体可以参考 [DP C++](https://leetcode.com/discuss/18970/concise-recursive-and-dp-solutions-with-full-explanation-in)，还可以压缩下把 dp 降成一维：


下面是那位大神的代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
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
