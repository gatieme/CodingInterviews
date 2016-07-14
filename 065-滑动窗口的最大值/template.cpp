#include <iostream>

using namespace std;


//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

/*  单调队列，O(n)
 *  引用马客（Mark）的解题思路，马客没加注释，我用自己的理解加下注释，希望对你们有用，
 *  如有错误，见谅，我会及时修改
 *  deque s中存储的是num的下标  */

class Solution
{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>     res;
        deque<int>      s;

        for(unsigned int i = 0; i < num.size(); i++)
        {
            /*  从后面依次弹出队列中比当前num值小的元素，
             *  同时也能保证队列首元素为当前窗口最大值下标  */
            while(s.size( ) != 0 && num[s.back( )] <= num[i])
            {
                s.pop_back( );
            }
            /*  当当前窗口移出队首元素所在的位置
                即队首元素坐标对应的num不在窗口中，需要弹出  */
            while(s.size() && i-s.front()+1>size)
            {
                s.pop_front();
            }
            /*  把每次滑动的num下标加入队列  */
            s.push_back(i); 
            /*  当滑动窗口首地址i大于等于size时才开始写入窗口最大值  */
            if(size != 0 && i + 1 >= size)
            {
                res.push_back(num[s.front( )]);
            }
        }
        return res;
    }
};



int __tmain( )
{
    Solution solu;

    int array[] = { 4, 4, 6, 6, 6, 5 };
    vector<int> vec(array, array + 6);

    vector<int> res = solu.maxInWindows(vec);
    copy(res.begin( ), res.end( ), ostream_iterator<int>(cout," "));

    return 0;
}
