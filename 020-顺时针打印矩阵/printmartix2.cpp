#include <iostream>
#include <vector>
#include <cassert>
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
    int n, m;
    vector<vector<bool> > v;
    bool judge(int i, int j)
    {
        return 0 <= i && i < n && 0 <= j && j < m && !v[i][j];
    }

public:
     vector<int> printMatrix(vector<vector<int> > a)
     {
        vector<int> r;
        if((n = a.size()) == 0 || (m = a[0].size()) == 0)
            return r;

        v = vector<vector<bool> >(n, vector<bool>(m, false));
        const int D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int i = 0, j = 0, d = 0, count = m * n;
        while(count--)
        {
            r.push_back(a[i][j]);
            v[i][j] = true;
            if(!judge(i + D[d][0], j + D[d][1]))
            {
                (++d) %= 4; //转弯
            }
            i += D[d][0];
            j += D[d][1];//前进
        }
        return r;
    }
};


int __tmain( )
{
    int a1[] = {  1,  2,  3,  4 };
    int a2[] = {  5,  6,  7,  8 };
    int a3[] = {  9, 10, 11, 12 };
    int a4[] = { 13, 14, 15, 16 };
//    int a1[] = { 1 };
//    int a2[] = { 2 };
//    int a3[] = { 3 };
//    int a4[] = { 4 };

    vector<int> vec1(a1, a1 + 4);
    vector<int> vec2(a2, a2 + 4);
    vector<int> vec3(a3, a3 + 4);
    vector<int> vec4(a4, a4 + 4);


    vector< vector<int> > vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);

    Solution solu;
    vector<int> res = solu.printMatrix(vec);
    for(int i = 0; i < res.size( ); i++)
    {
        cout <<res[i] <<" ";
    }
    return 0;
}
