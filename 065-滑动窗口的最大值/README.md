#链接
-------

>牛客OJ：[滑动窗口的最大值](http://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=4)
>
>九度OJ：未收录
>
>GitHub代码： [065-滑动窗口的最大值](https://github.com/gatieme/CodingInterviews/tree/master/038-数字在排序数组中出现的次数)
>
>CSDN题解：[剑指Offer--065-滑动窗口的最大值](http://blog.csdn.net/gatieme/article/details/51330871)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 |
| ------- |:-------:|:-------:| -------:|
|[038-数字在排序数组中出现的次数](http://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=4) | 未收录 |  [剑指Offer--065-滑动窗口的最大值](https://github.com/gatieme/CodingInterviews/tree/master/038-数字在排序数组中出现的次数) | [065-滑动窗口的最大值](https://github.com/gatieme/CodingInterviews/tree/master/038-数字在排序数组中出现的次数) |


#题意
-------

**题目描述**

题目描述

>给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值


例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3

那么一共存在6个滑动窗口, 他们的最大值分别为{4,4,6,6,6,5}；

针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个
{[2,3,4],2,6,2,5,1}，
{2,[3,4,2],6,2,5,1}，
{2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}，
{2,3,4,2,[6,2,5],1}，
{2,3,4,2,6,[2,5,1]}。