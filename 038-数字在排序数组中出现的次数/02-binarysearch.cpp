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



/* 先用二分查找找出某个k出现的位置，然后再分别向前和向后查找总的个数*/
class Solution
{

public:
    int GetNumberOfK(vector<int> data,int key)
    {
        if(data.size( ) == 0)
        {
            return 0;
        }

        //  用二分查找查找到Key的位置
        int index = BinarySearch(data, 0, data.size( ) - 1, key);
        //int index = BinarySearch(data, key);
        if(index == -1)
        {
            return 0;
        }

        int count = 1;
        // 查找前面部分Key的个数
        for(int j = index - 1;
            j >= 0 && data[j] == key;
            j--)
        {
            debug <<"pos = " <<j <<", data = " <<data[j] <<endl;
            count++;
        }

        //  查找后面部分Key的个数
        for(int j = index + 1;
            j < (int)data.size( ) && data[j] == key;
            j++)
        {
            count++;
        }

        return count;
    }

    int BinarySearch(vector<int> &data, int begin, int end ,int key)
    {
        if(begin > end)
        {
            return -1;
        }

        int mid = (begin + end) / 2;
        debug <<"mid = " <<mid <<", data = " <<data[mid] <<endl;
        if(data[mid] == key)
        {
            return mid;
        }
        else if(data[mid] > key)
        {
            return BinarySearch(data, begin, mid - 1, key);
        }
        else if(data[mid] < key)
        {
            return BinarySearch(data,mid + 1, end, key);
        }
        return -1;
    }


    int BinarySearch(vector<int> array, int key)
    {
        int low = 0, high = array.size( ) - 1;

        int mid;

        while (low <= high)
        {
            mid = (low + high) / 2;

            if(key == array[mid])
            {
                return mid;
            }

            if(key < array[mid])
            {
                high = mid - 1;
            }

            if(key > array[mid])
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};


int __tmain( )
{
    Solution solu;

    int arr[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
    vector<int> vec(arr, arr + 8);
    cout <<solu.GetNumberOfK(vec, 5) <<endl;

    return 0;
}
