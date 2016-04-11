/* 
 * Question Description:
 * (Question 18 in <Coding Intervies>) Given a node in a binary tree, please implement a function to retrieve 
 * its next node in the inorder traversal sequence. There is a pointer to the parent node in each tree node. 
*/

#include <stdio.h>

struct BinaryTreeNode 
{
    int                    m_nValue; 
    BinaryTreeNode*        m_pLeft;  
    BinaryTreeNode*        m_pRight;
    BinaryTreeNode*        m_pParent; 
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == NULL)
        return NULL;
    
    BinaryTreeNode* pNext = NULL;
    if(pNode->m_pRight != NULL)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != NULL)
            pRight = pRight->m_pLeft;
            
        pNext = pRight;
    }
    else if(pNode->m_pParent != NULL)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != NULL && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        
        pNext = pParent;
    }
    
    return pNext;
}

// ==================== Code for Binary Trees ====================
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = NULL;
    pNode->m_pRight = NULL;
    pNode->m_pParent = NULL;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != NULL)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
        
        if(pLeft != NULL)
            pLeft->m_pParent = pParent;
        if(pRight != NULL)
            pRight->m_pParent = pParent;
    }
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
    if(pNode != NULL)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if(pNode->m_pLeft != NULL)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");

        if(pNode->m_pRight != NULL)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->m_pLeft != NULL)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != NULL)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != NULL)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = NULL;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// ==================== Test Code ====================
void Test(char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
        
    BinaryTreeNode* pNext = GetNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, NULL);

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);

    Test("Test8", pNode5, NULL);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);
    Test("Test11", pNode2, pNode3);

    DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test("Test12", pNode5, NULL);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);

    DestroyTree(pNode2);
}

void Test16()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    Test("Test16", pNode5, NULL);

    DestroyTree(pNode5);
}

int main(int argc, char* argv[])
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
}