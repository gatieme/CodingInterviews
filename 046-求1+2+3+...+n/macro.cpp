#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class base;
base *parray[2];

class base{
public:
    virtual unsigned int sum(unsigned int n)
    {
        //  递归的终止
        return 0;
    }
};

class derive :public base{
public:
    virtual unsigned int sum(unsigned int n)
    {
        //  !!n两次非运算, 从而将n转换为bool类型, 来选择函数
        //  sum(n) = sum(n - 1) + n 则是递归公式
        return parray[!!n]->sum(n - 1) + n;
    }
};


class Solution {
public:
    int Sum_Solution(int n) {

        base a;
        derive b;

        parray[0] = &a;
        parray[1] = &b;

        return parray[1]->sum(n);
    }
};


int main(){

    Solution s;

    cout<<s.Sum_Solution(10);

    return 0;
}



