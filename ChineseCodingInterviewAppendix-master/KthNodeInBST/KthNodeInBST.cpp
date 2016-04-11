/* 
 * Question Description:
 * (Question 84 in <Coding Intervies>) How do you get the kth node in a binary search tree in an incremental order of values? 
*/

#include <stdlib.h>
#include <stdio.h>
#include "../Utilities/BinaryTree.h"

BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int& k);

BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k)
{
    if(pRoot == NULL || k == 0)
        return NULL;
    
    return KthNodeCore(pRoot, k);
}

BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int& k)
{
    BinaryTreeNode* target = NULL;
    
    if(pRoot->m_pLeft != NULL)
        target = KthNodeCore(pRoot->m_pLeft, k);
    
    if(target == NULL)
    {
        if(k == 1)
            target = pRoot;
        
        k--;
    }
    
    if(target == NULL && pRoot->m_pRight != NULL)
        target = KthNodeCore(pRoot->m_pRight, k);
    
    return target;
}

void Test(char* testName, BinaryTreeNode* pRoot, unsigned int k, bool isNull, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    BinaryTreeNode* pTarget = KthNode(pRoot, k);
    if((isNull && pTarget == NULL) || (!isNull && pTarget->m_nValue == expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void TestA()
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

    Test("TestA0", pNode8, 0, true, -1);
    Test("TestA1", pNode8, 1, false, 5);
    Test("TestA2", pNode8, 2, false, 6);
    Test("TestA3", pNode8, 3, false, 7);
    Test("TestA4", pNode8, 4, false, 8);
    Test("TestA5", pNode8, 5, false, 9);
    Test("TestA6", pNode8, 6, false, 10);
    Test("TestA7", pNode8, 7, false, 11);
    Test("TestA8", pNode8, 8, true, -1);

    DestroyTree(pNode8);
    
    printf("\n\n");
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void TestB()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode1, NULL);

    Test("TestB0", pNode5, 0, true, -1);
    Test("TestB1", pNode5, 1, false, 1);
    Test("TestB2", pNode5, 2, false, 2);
    Test("TestB3", pNode5, 3, false, 3);
    Test("TestB4", pNode5, 4, false, 4);
    Test("TestB5", pNode5, 5, false, 5);
    Test("TestB6", pNode5, 6, true, -1);

    DestroyTree(pNode5);

    printf("\n\n");
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void TestC()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test("TestC0", pNode1, 0, true, -1);
    Test("TestC1", pNode1, 1, false, 1);
    Test("TestC2", pNode1, 2, false, 2);
    Test("TestC3", pNode1, 3, false, 3);
    Test("TestC4", pNode1, 4, false, 4);
    Test("TestC5", pNode1, 5, false, 5);
    Test("TestC6", pNode1, 6, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// There is only one node in a tree
void TestD()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    Test("TestD0", pNode1, 0, true, -1);
    Test("TestD1", pNode1, 1, false, 1);
    Test("TestD2", pNode1, 2, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// empty tree
void TestE()
{
    Test("TestE0", NULL, 0, true, -1);
    Test("TestE1", NULL, 1, true, -1);

    printf("\n\n");
}

int main(int argc, char* argv[])
{
    TestA();
    TestB();
    TestC();
    TestD();
    TestE();
}