#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

#include <climits>

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
public :
    /*  方式二：利用队列来解决,时间复杂度为O(n)
        利用双端队列来实现单调队列(索引对应的值是单调的)  */
   vector<int> maxInWindows(const vector<int>& num, unsigned int size)
   {
        unsigned int length = num.size( );
        vector<int> result;

        if(length == 0 || size == 0 || length < size)
        {
            return result;
        }

        deque<int> indexQueue;

        /*  第一个窗口的处理比较简单, 直接找到最大的那个即可  */
        for(unsigned int i = 0;
            i < size;
            i++)
        {
            /*  删除队尾元素
             *  对于当前元素num[i]
             *  前面比k小的，直接移出队列
             *  因为不再可能成为后面滑动窗口的最大值了  */
            while(indexQueue.empty( ) != true
               && num[i] >= num[indexQueue.back( )])
            {
                indexQueue.pop_back( );
            }
            /*  将当前元素的下表压入队列中  */
            indexQueue.push_back(i);
        }

        /* 处理后续的滑动窗口*/
        for(unsigned int i = size;
            i < length;
            i++)
        {
            /*  队列中的第一个元素是当前滑动窗口最大值的下标  */
            result.push_back(num[indexQueue.front()]);

            /*  删除队尾元素
             *  对于当前元素num[i]
             *  前面比k小的，直接移出队列
             *  因为不再可能成为后面滑动窗口的最大值了  */
            while(indexQueue.empty( ) != true
               && num[i]>=num[indexQueue.back()])
            {
                indexQueue.pop_back();
            }

            /*  删除队首元素
             *  前面比k大的X，
             *  比较两者下标，判断X是否已不在窗口之内，
             *  不在了，直接移出队列  */
            if(indexQueue.empty( ) != true
            && indexQueue.front( ) < (int)(i - size + 1))
            {
                indexQueue.pop_front( );
            }
            indexQueue.push_back(i);
        }
        result.push_back(num[indexQueue.front()]);
        return result;
    }
};

int __tmain( )
{
    Solution solu;

    int array[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    vector<int> vec(array, array + 8);

    vector<int> res = solu.maxInWindows(vec, 3);
    copy(res.begin( ), res.end( ), ostream_iterator<int>(cout," "));

    return 0;
}
