#链接
------- 
>牛客OJ：[数组中重复的数字](http://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking)
> 
>九度OJ：未收录
> 
>GitHub代码： [051-数组中重复的数字](https://github.com/gatieme/CodingInterviews/tree/master/051-数组中重复的数字)
>
>CSDN题解：[剑指Offer--051-数组中重复的数字](http://blog.csdn.net/gatieme/article/details/51540159)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| -----:|
|[051-数组中重复的数字](http://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking) | 未收录 | [剑指Offer--051-数组中重复的数字](http://blog.csdn.net/gatieme/article/details/51540159) | [051-数组中重复的数字](https://github.com/gatieme/CodingInterviews/tree/master/051-数组中重复的数字) |


#题意
-------


**题目描述**

>在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
>
>数组中某些数字是重复的，但不知道有几个数字是重复的。
>
>也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
>
>例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。

**样例输入**

>2, 3, 1, 0, 2, 5, 3
>
> 2, 1, 3, 1, 4


**样例输出**

>2
>
>1

#检查数据的合法性 
-------

*    检查输入参数是否合法

*    数组中的数据是否满足所有数字都在0到n-1的范围内

```cpp
bool CheckValidity(int *numbers, int length)
{
    //  输入数据不合法
    if(numbers == NULL || length <= 0)
    {
        return false;
    }

    //  元素必须在[0, n-1]的范围
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
        {
            return false;
        }
    }

    return true;
}
```


#排序后判断重复
-------

最简单的思路就是先把输入的数组排序。从排序的数组中找出重复的数字就是个很容易的事情了。只需要从头向尾扫描一遍排序好的数组即可。

对一个数组排序的时间复杂度是$O(nlogn)$

扫描一个排序好的数组发现重复的数字的时间复杂度是$O(n)$


```cpp
class Solution
{
public:
    bool duplicate(int numbers[], int length, int* duplication)
    {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }

        sort(numbers, numbers + length);    //  对数组进行排序

        int i = 0;
        bool isDup = false;
        *duplication = -1;

        //  扫描一遍数组发现重复的数字
        for(i = 0; i < length - 1; i++)
        {
            if(numbers[i] == numbers[i + 1])    //  重复了
            {
                isDup = true;
                *duplication = numbers[i];
                break;
            }
        }

        return isDup;
    }
};

```



#hashtable哈希法优化查找速率

-------

当然我们用hashtabble也可以实现，

hashtable中可以很方便的查找到某个元素是否存在，时间负责度$O(n)$,空间复杂度$O(n)$

```cpp
class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {

        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }

        set<int> s;
        bool isDup = false;
        *duplication = -1;
        for(int i = 0; i < length; i++)
        {
            if(s.count(numbers[i]) == 1)  // 如果当前元素已经存在set中
            {
                isDup = true;
                *duplication = numbers[i];
                break;
            }
            s.insert(numbers[i]);

        }

        return isDup;
    }
};
```



#标识数组法

------

hashtable的方式是在优化查找的过程，因为hashtable查找的时间复杂度为$O(1)$,

那么我们继而联想到，如果不设hash，直接用一个用一个数组flag当前标识，记录某个元素是否出现, 

>flag[i] =0标识元素i未出现,
> 
>flag[i] =1标识元素i出现

这样也可以在$O(1)$的时间内实现判断



##空间$O(n)$的标识数组

-------


```cpp
class Solution
{
public:
    bool duplicate(int numbers[], int length, int* duplication)
    {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }
        int flags[length];
        memset(flags, 0, sizeof(flags));
        for(int i = 0; i < length; i++)
        {
            if(flags[numbers[i]] != 0)
            {
                *duplication = numbers[i];
                return true;
            }
            else
            {
                flags[numbers[i]] = 1;
            }
        }

        return false;
    }

};
```



我们采用了一个以空间换时间的方式, 但是有没有什么办法能够优化空间上的消耗呢?

因为我们需要的只是一个标识, 0或者1,那么我们完全没必要一个整数来做标识，

因此可做如下优化



>用一个n位的单元来存储即可, 每一位都是一个标识



这种方法可以把空间消耗将低, 但是还是需要额外的空间，那么有没有不需要空间消耗的方法呢?



##符号位标识法
-------



我们可以看到数组中元素的大小都在[0-n)这个区间内, 都是正数，那么他们的符号位对我们来说就是无关紧要的, 因此我们直接拿符号位当成我们的标识位就行了

>numbers[i]符号位为0表示数字i没有重复
>
>numbers[i]符号位为1标识数字i重复



```cpp
#define SET_SYMBOL_BIT(num)  ((num) |= (1 << 31))		/*  设置符号位为1 */
#define GET_ORIGIN_NUM(num)  ((num) & (~(1 << 31)))		/*	获取到源数据  */
#define GET_SYMBOL_BIT(num)  (((num) >> 31) & 1)		/*  获取符号位(标识)*/

class Solution
{
public:
    /*
        对于每一个数据numbers[i]
        其源数据origin = GET_ORIGIN_NUM(numbers[i])的标识存储在numbers[origin]的符号位
        判断其标识是否为1即可
    */
    bool duplicate(int numbers[], int length, int* duplication)
    {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }
        for(int i = 0; i < length; i++)
        {
            //  当前数字numbers[i]的标识即是numbers[numbers[i]]的符号位
            //  检查numbers[i]
            debug <<"origin = " <<GET_ORIGIN_NUM(numbers[i]) <<", flag = " <<GET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]) <<endl;
            if(GET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]) == 1)
            {
                *duplication = GET_ORIGIN_NUM(numbers[i]);
                return true;
            }
            else
            {
                SET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]);
                debug <<"SET origin = " <<GET_ORIGIN_NUM(numbers[i]) <<", flag = " <<GET_SYMBOL_BIT(numbers[GET_ORIGIN_NUM(numbers[i])]) <<endl;
            }
        }

        return false;
    }

};
```



#固定偏移法
-------



跟标识法类似, 如果不借助外部辅助空间，那么我们只能在数组内部下功夫，又能设置标识，又能恢复数据（不破坏数据）的方式，前面我们用符号位作为标识的方法就是通过符号位，即判断了是否存在，又可以通过符号位的反转重新恢复数据，那么有没有其他类似的方法呢？



我们想到我们的数据都是[0, n)这个区间的，那么我们采用类似与移码的方法，让数据加上或者减去一个固定的偏移量，这样就可以即标识数据，又不损坏数据,为了能够区分出数据，这个偏移必须大于N，这样我们的原数据与标识数据存在一一映射关系。



>[0, n-1]  -=>+偏移n-=> [n, 2n-1]



```cpp
class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }

        for(int i = 0; i < length; i++)
        {
            if(numbers[numbers[i] % length] >= length)
            {
                *duplication = numbers[i] % length;
                return true;
            }
            else
            {
                numbers[numbers[i] % length] += length;
            }
        }

        return false;

    }
};

```



#将元素放在自己改在的位置
-------

剑指offer上提供的方法，这种方法采用交换的方法

我们考虑如果每个数字都置出现一次，那么此时是最完美的，<font color=00ff99>每一个下标i对应元素numbers[i]</font>，也就是说我们对于数组中的每个元素numbers[i]都把它放在自己应该在的位置上numbers[numbers[i]]上, 如果我们发现有两个元素想往同一个位置上放的时候，说明此元素必然重复

即如下的过程

1.    如果numbers[i] == i, 那么我们认为number[i]这个元素是在自己的位置上的



2.    否则的话, numbers[i]这个元素就应该在numbers[numbers[i]]这个位置上, 于是我们交换numbers[i]和numbers[numbers[i]]



3.    重复操作1, 直到number[i]== i, 则继续操作下一个位置的元素, 或者numbers[i] == numbers[numbers[i]，元素重复



```cpp
class Solution
{
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {
        *duplication = -1;

        if(CheckValidity(numbers, length) == false)
        {
            return false;
        }

        for(int i = 0; i < length; i++)
        {
            // 极端情况按顺序排序, 第i个位置上的数numbers[i]应该等于其下标i
            while(numbers[i] != i)
            {
                debug <<"numbers[" <<i <<"] = " <<numbers[i] <<" isn't equal to it's index = " <<i <<endl;
                //  第numbers[i]位置上的数据numbers[numbers[i]应该是numbers[i]
                //  即数numbers[i]应该是数组第numbers[i]个数numbers[numbers[i]
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                debug <<"swap numbers[" <<i <<"] and numbers[" <<numbers[i] <<"]" <<endl;
                swap(numbers[i], numbers[numbers[i]]);
            }
            debug <<"numbers[" <<i <<"] = " <<numbers[i] <<" is equal to it's index = " <<i <<endl;

        }

        return false;

    }

};

```