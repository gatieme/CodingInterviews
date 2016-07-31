#include <iostream>
#include <vector>
#include <iterator>

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

        vector<int> temp(elem.size( ));
        int count = InversePairsCore(elem, 0, elem.size( ) - 1, temp);

        return count;
    }

    int MergeElem(vector<int> &elem, int start, int mid, int end, vector<int> &temp)//数组的归并操作
    {
        // int leftLen=mid-start+1; //elem[start...mid]左半段长度
        // int rightLlen=end-mid;   //elem[mid+1...end]右半段长度

        int i = mid;
        int j = end;
        int k = 0;      //  临时数组末尾坐标
        int count = 0;

        //  设定两个指针i, j分别指向两段有序数组的尾元素, 将小的那一个放入到临时数组中去.
        while(i >= start && j > mid)
        {
            if(elem[i] > elem[j])
            {
                temp[k++] = elem[i--];  //  从临时数组的最后一个位置开始排序
                count += j - mid;       //  因为elem[mid+1...j...end]是有序的，如果elem[i]>elem[j]，那么也大于elem[j]之前的元素，从a[mid+1...j]一共有j-(mid+1)+1=j-mid
            }
            else
            {
                temp[k++] = elem[j--];
            }
        }

        debug <<"count = " <<count <<endl;
        while(i >= start)//表示前半段数组中还有元素未放入临时数组
        {
            temp[k++] = elem[i--];
        }

        while(j > mid)
        {
            temp[k++] = elem[j--];
        }

        //将临时数组中的元素写回到原数组当中去。
        for(i = 0; i < k; i++)
        {
            elem[end-i] = temp[i];
        }

        return count;

    }

    int InversePairsCore(vector<int> &elem,int start,int end, vector<int> &temp)
    {
        int inversions = 0;
        if(start < end)
        {
            int mid = (start + end) / 2;
            inversions += InversePairsCore(elem, start, mid, temp);     //  找左半段的逆序对数目
            inversions += InversePairsCore(elem, mid + 1, end, temp);   //  找右半段的逆序对数目
            inversions += MergeElem(elem,start, mid, end, temp);        //  在找完左右半段逆序对以后两段数组有序, 然后找两段之间的逆序对. 最小的逆序段只有一个元素.
        }

        return inversions;
    }
};

int __tmain( )
{
    Solution solu;

    int arr[] = { 7, 5, 6, 4 };
    vector<int> vec(arr, arr + 4);

    cout <<solu.InversePairs(vec) <<endl;
    return 0;
}
