/* 
 * Question Description:
 * (Question 52 in <Coding Intervies>) Please implement a function to verify whether a binary tree is symmetrical. 
 * A tree is symmetrical if its mirrored image looks the same as the tree itself. 
*/

#include <stdio.h>
#include "../Utilities/BinaryTree.h"

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

bool isSymmetrical(BinaryTreeNode* pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if(pRoot1 == NULL && pRoot2 == NULL)
        return true;
    
    if(pRoot1 == NULL || pRoot2 == NULL)
        return false;
    
    if(pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
        
    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
        && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

// ==================== Test Code ====================
void Test(char* testName, BinaryTreeNode* pRoot, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(isSymmetrical(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, pNode52);

    Test("Test1", pNode8, true);

    DestroyTree(pNode8);
}

//            8
//        6      9
//       5 7    7 5
void Test2()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode8, pNode61, pNode9);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode9, pNode72, pNode52);

    Test("Test2", pNode8, false);

    DestroyTree(pNode8);
}

//            8
//        6      6
//       5 7    7
void Test3()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, NULL);

    Test("Test3", pNode8, false);

    DestroyTree(pNode8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode21, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode21, pNode11, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test4", pNode5, true);

    DestroyTree(pNode5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void Test5()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode6, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode6, pNode11, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test5", pNode5, false);

    DestroyTree(pNode5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void Test6()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode21, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode21, NULL, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test6", pNode5, false);

    DestroyTree(pNode5);
}

// Only one node
void Test7()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test7", pNode1, true);

    DestroyTree(pNode1);
}

// No nodes
void Test8()
{
    Test("Test8", NULL, true);
}

// All nodes have the same value
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void Test9()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, NULL, NULL);
    ConnectTreeNodes(pNode42, NULL, NULL);

    Test("Test9", pNode1, true);

    DestroyTree(pNode1);
}

// All nodes have the same value
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void Test10()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, pNode42, NULL);
    ConnectTreeNodes(pNode41, NULL, NULL);
    ConnectTreeNodes(pNode42, NULL, NULL);

    Test("Test10", pNode1, false);

    DestroyTree(pNode1);
}

void main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
}