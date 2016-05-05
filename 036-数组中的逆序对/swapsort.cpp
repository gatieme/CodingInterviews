#include <iostream>
#include <vector>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
public:
    int InversePairs(vector<int> elem)
    {
        if(elem.size( ) == 0)
        {
            return 0;
        }

        return BubbleSort(elem);
    }

    int BubbleSort(vector<int> elem)
    {
        bool flag = true;
        int count = 0;
        unsigned int length = elem.size( );

        for(unsigned int i = 0;
            i < length - 1 && flag == true;
            i++)  // 共计进行length-1趟循环
        {
            flag = false;           // 初始默认数据是无序的
            for(unsigned int j = 0;
                j < length - i - 1;
                j++)   // 每趟循环比较length-1-j次
            {
                if(elem[j] > elem[j + 1])    // 如果当前的元素与后一个元素不满足排序规则
                {
                    swap(elem[j], elem[j+1]);
                    flag = true;  // 仍然需要交换说明, 仍然无序
                    count++;
                }
            }
        }

        return count;
    }

    int Quick_Sort(vector<int> &numbers, int left, int right)
    {
        static int count = 0;

        if(left >= right)
        {
            return count;
        }
        int i = left, j = right;

        ///  我们选择第一个元素作为基准
        ///  这个也可以随机选择
        int pivotIndex = left, pivotNum = numbers[pivotIndex];

        debug <<"pivotNum = " <<pivotNum <<endl;

        while(i < j)
        {
            while(i < j && numbers[j] >= pivotNum)
            {
                debug <<"[" <<i <<", " <<j <<"] " <<numbers[j] <<" >= " <<pivotNum <<endl;
                j--;
                count++;
            }
            debug <<"now we find i = " <<i <<", posJ = " <<j <<", num = " <<numbers[j] <<" < " <<pivotNum <<endl;;
            numbers[i] = numbers[j];        // 将找到的那个比枢轴小的数，放在枢轴左侧I的位置
            //swap(numbers[i], numbers[j]); // 也可以使用交换, 但是没有必要, 因为枢轴的位置并没有最后确定


            while(i < j && numbers[i] <= pivotNum)
            {
                debug <<"[" <<i <<", " <<j <<"] " <<numbers[i] <<" <= " <<pivotNum <<endl;
                i++;
                count++;
            }

            debug <<"now we find j = " <<i <<", posI = " <<j <<", num = " <<numbers[i] <<" > " <<pivotNum <<endl;;
            numbers[j] = numbers[i];        // 将找到的那个比枢轴大的数，放在枢轴右侧J的位置
            //swap(numbers[i], numbers[j]); // 也可以使用交换, 但是没有必要, 因为枢轴的位置并没有最后确定

        }

        numbers[i] = pivotNum;              //  最后的位置 i == j 就是枢轴的位置

        Quick_Sort(numbers, left, i - 1);
        Quick_Sort(numbers, i + 1, right);

        return count;
    }


};

int __tmain( )
{
    Solution solu;

    int arr[] = { 7, 5, 6, 4 };
    vector<int> vec(arr, arr + 4);

    cout <<solu.Quick_Sort(vec, 0, 3) <<endl;

    return 0;
}
