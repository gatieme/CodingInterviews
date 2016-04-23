#include <iostream>
#include <map>

using namespace std;

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x)
    :label(x), next(NULL), random(NULL)
    {
    }
};

class Solution
{
public:

    ///  复制操作
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }
        map<RandomListNode *, RandomListNode *> nodeMap;

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  首先复制原链表的普通指针域, 一次遍历即可完成
        while(currNode != NULL)
        {
            newNode = new RandomListNode(currNode->label);
            nodeMap[currNode] = newNode;
            currNode = currNode->next;

            if(preNode == NULL)
            {
                newHead = newNode;
            }
            else
            {
                preNode->next = newNode;
            }

            preNode = newNode;
        }

        //  接着复制随机指针域, 需要两次遍历
        currNode = pHead;
        newNode = newHead;
        while(currNode != NULL && newNode != NULL)
        {
            RandomListNode *randNode = currNode->random;                        ///  随机指针域randNode
            RandomListNode *newRandNode = nodeMap[randNode];
            newNode->random = newRandNode;

            ///  链表同步移动
            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }

};


int main( )
{

}


