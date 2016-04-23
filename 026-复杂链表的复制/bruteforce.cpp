class Solution
{
public:
    ///  找到newHead指向的新链表中与原来链表oldHead的randNode节点对应的那个节点
    ///
    ///  复制的链表newHead与原链表oldHead存在一一对应的关系
    ///  因此使用两个指针(一个指向原来链表一个指向新链表)同步移动
    ///  即可找到newHead指向的新链表中与原来链表oldHead的randNode节点对应的那个节点
    RandomListNode* FindInNew(RandomListNode *oldHead, RandomListNode *newHead, RandomListNode *randNode)
    {
        RandomListNode *currNode = oldHead;
        RandomListNode *newNode = newHead;

        while(currNode != NULL && newNode != NULL)
        {
            if(randNode == currNode)
            {
                return newNode;
            }
            currNode = currNode->next;
            newNode = newNode->next;
        }

        return NULL;
    }

    ///  复制操作
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
        {
            return NULL;
        }

        RandomListNode *currNode = pHead;
        RandomListNode *newHead = NULL, *preNode = NULL, *newNode = NULL;

        ///  首先复制原链表的普通指针域, 一次遍历即可完成
        while(currNode != NULL)
        {
            newNode = new RandomListNode(currNode->label);
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
            RandomListNode *newRandNode = FindInNew(pHead, newHead, randNode);  ///  查找到新链表中与randNode对应的指针域
            newNode->random = newRandNode;

            ///  链表同步移动
            currNode = currNode->next;
            newNode = newNode->next;
        }

        return newHead;
    }

};
