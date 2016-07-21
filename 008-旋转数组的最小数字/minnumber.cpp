#include <iostream>
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
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size( ) == 0)
        {
            debug <<"非法输入" <<endl;
            return 0;
        }

        int low = 0, high = rotateArray.size( ) - 1;
        //  如果把排序数组前面0个元素搬到后面，也就是说其实没有旋转，
        //  那么第0个元素就是最小的元素
        //  因此我们将mid初始化为0
        int mid = low;
#ifdef __tmain
        if(rotateArray[low] < rotateArray[high])
        {
            debug <<"数组未被旋转" <<endl;
        }
#endif
        while(rotateArray[low] >= rotateArray[high])
        {
            //  如果前一个元素与后一个元素差一位
            //  说明找到了最大最小的元素
            if(high - low == 1)
            {
                mid = high;
                debug <<"min = " <<low <<", high = " <<high <<endl;
                break;
            }

            mid = (low + high) / 2;
            debug <<rotateArray[low] <<", " <<rotateArray[mid] <<", " <<rotateArray[high] <<endl;

            // rotateArray[low] rotateArray[mid] rotateArray[high]三者相等
            // 无法确定中间元素是属于前面还是后面的递增子数组
            // 只能顺序查找
            if(rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high])
            {
                debug <<"low == mid == high, so we should order it" <<endl;
                return MinOrder(rotateArray, low, high);
            }

            //  如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素
            if(rotateArray[mid] >= rotateArray[low])
            {
                low = mid;          //  此时最小的元素位于中间元素的后面
            }
            // 如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指 向的元素
            else if(rotateArray[mid] <= rotateArray[high])
            {
                high = mid;         //  此时最小的元素位于中间元素的前面
            }
        }

        return rotateArray[mid];
    }

private:
    // 顺序寻找最小值
    int MinOrder(vector<int> &num, int low, int high)
    {
        int result = num[low];
        for(int i = low + 1; i < high; i++)
        {
            if(num[i] < result)
            {
                result = num[i];
            }//if
        }//for
        return result;
    }
};

int __tmain( )
{

    int a[] = { 1, 0, 1, 1, 1,};
    vector<int> vec(a, a + 5);

    Solution solu;
    cout <<solu.minNumberInRotateArray(vec) <<endl;

    return 0;
}
