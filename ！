#链接
------- 

>牛客OJ：[二叉树的镜像](http://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
> 
>九度OJ：http://ac.jobdu.com/problem.php?pid=1521
> 
>GitHub代码： [019-二叉树的镜像](https://github.com/gatieme/CodingInterviews/tree/master/019-二叉树的镜像)
>
>CSDN题解：[剑指Offer--019-二叉树的镜像](http://blog.csdn.net/gatieme/article/details/51175749)


| 牛客OJ | 九度OJ | CSDN题解 | GitHub代码 | 
| ------------- |:-------------:| -----:| 
|[二叉树的镜像](http://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking) | [1521-二叉树的镜像](http://ac.jobdu.com/problem.php?pid=1521) | [剑指Offer--019-二叉树的镜像](http://blog.csdn.net/gatieme/article/details/51175749) | [019-二叉树的镜像](https://github.com/gatieme/CodingInterviews/tree/master/019-二叉树的镜像) |


<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**



#题意

-------

**题目描述**

操作给定的二叉树，将其变换为源二叉树的镜像。 

**输入描述**

二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5


#分析
------
通过画图，可知二叉树的镜像如下图所示：

![二叉树的镜像](http://img.blog.csdn.net/20160417214454538)

中间像放置了一面镜子，将源二叉树投射在镜子中

通常的思路，我们创建一个树以后，交换没个节点的左右孩子就行了。


因此我们只需要遍历二叉树，然后每次访问（输出）一个节点的时候。交换其左右孩子即可

于是我们实现了下面的递归，非递归的函数版本，其本质是相同的，就是把前序中序，后序遍历中的打印节点的过程，编程交换左右子树的过程，其中需要注意一点，就是交换后左右子树进行了交换，再往下走的时候，往左走往右走的过程需改变，原来的向右走，现在应该是向左走，



#递归方法
-------

采用递归思路，层层交换节点的左右孩子指针。
```cpp

class Solution
{
public:
    void Mirror(TreeNode *pRoot)
    {

        if(pRoot == NULL)
        {
            return;
        }

        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }

};
```




#非递归

-------

##前序遍历

前序遍历的过程中，先根，再左再右，

由于根后面才对左右子树进行访问，因此访问顺序可不交换，我们此时的访问顺序依旧是根左右，但是对应原来的根右左



```cpp

class Solution
{
public:
    void MirrorPre(TreeNode *root)
    {
        if(root == NULL)
        {
            return ;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        while(node != NULL
           || nstack.empty( ) != true)
        {
            while(node != NULL)
            {
                if(node->left != NULL || node->right != NULL)
                {
                    swap(node->left, node->right);
                }

                nstack.push(node);
                node = node->left;
            }

            if(nstack.empty( ) != true)
            {
                node = nstack.top( );
                nstack.pop( );
                node = node->right;
            }
        }
    }

    void MirrorPreBFS(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        stack<TreeNode *> nstack;
        nstack.push(root);

        TreeNode *node = root;
        while(nstack.empty() != true)
        {
            node = nstack.top( );
            nstack.pop( );

            //  先交换, 然后递归左，接着递归右
            //  相当与一次前序遍历
            if(node->left != NULL || node->right != NULL)
            {
                swap(node->left, node->right);
            }

            if(node->left != NULL)
            {
                nstack.push(node->left);
            }
            if(node->right != NULL)
            {
                nstack.push(node->right);
            }
        }
    }

};
```





##中序遍历

-------

中序遍历的时候，访问顺序左根右，由于访问后，依然要向右走，

所以交换后，变成了向左走



```cpp

class Solution
{
public:
    void MirrorIn(TreeNode *root)
    {
        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
            return NULL;
        }

        stack<TreeNode *> nstack;
        TreeNode *node = root;

        //  开始遍历整个二叉树
        while(node != NULL || nstack.empty() != true)
        {
            // 不输出当前根节点，但是递归直至当前根节点node的最左端
            while(node != NULL)
            {
                nstack.push(node);
                node = node->left;
            }

            //  此时栈顶的元素是当前最左元素
            //  它应该被输出
            if(nstack.empty( ) != true)
            {
                node = nstack.top( );

                //  将原来的输出改为交换左右子树即可
                if(node->left != NULL || node->right != NULL)
                {
                    swap(node->left, node->right);
                }

                nstack.pop( );
                //  中序遍历输出根后，向右转向
                //  此时由于左右子树交换，因此原来的右子树是其左子树，向左转向
                node = node->left;
            }
        }
    }

};
```




##后序遍历
-------

跟先序访问一样，访问了左右才会访问根，访问顺序变了


```cpp
class Solution
{
public:
    void MirrorPost(TreeNode *root)
    {

        if(root == NULL)
        {
            debug <<"The tree is NULL..." <<endl;
            return;
        }
        stack<TreeNode *> nstack;

        TreeNode *cur;                      //当前结点
        TreeNode *pre = NULL;                 //前一次访问的结点
        nstack.push(root);

        while(nstack.empty( ) != true)
        {
            cur = nstack.top( );

            if((cur->left == NULL && cur->right == NULL)                     //  左右还是均为NULL, 可以被输出
            || (pre != NULL && ((pre == cur->left /*&& cur->right == NULL*/) || pre == cur->right)))     //  左右还是被输出了, 递归返回

            {
                ///cout<<cur->val;  //如果当前结点没有孩子结点或者孩子节点都已被访问过
                            //  将原来的输出改为交换左右子树即可
                if(cur->left != NULL || cur->right != NULL)
                {
                    swap(cur->left, cur->right);
                }

                nstack.pop( );
                pre = cur;
            }
            else
            {
                // 由于栈是先进后出，因此先如后孩子, 再左孩子可以保证递归返回时先遍历左孩子
                if(cur->right != NULL)
                {
                    nstack.push(cur->right);
                }

                if(cur->left != NULL)
                {
                    nstack.push(cur->left);
                }
            }
        }
    }


};

```

