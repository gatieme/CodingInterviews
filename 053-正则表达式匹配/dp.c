/*************************************************************************
    > File Name: regex.c
    > Author: GatieMe
    > Mail: gatieme@163.com
    > Created Time: 2016年04月03日 星期日 10时22分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>



#define __tmain main

//  动态规划
//  用数组 DP :dp[i][j] 表示 s[0..i] 和 p[0..j] 是否 match，
//
//  当 p[j] != '*'，b[i + 1][j + 1] = b[i][j] && s[i] == p[j] ，
//
//  当 p[j] == '*' 要再分类讨论，
//
//  具体可以参考 DP C++，还可以压缩下把 dp 降成一维
//
//  用记忆化，就是把算过的结果保存下来，下次就不用再算了
int dp[100][100];

bool isMatch(char* str, char* regex)
{


}








int __tmain(void)
{


    return EXIT_SUCCESS;

}


