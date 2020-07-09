// Given a binary tree

//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

//     Note:

//         You may only use constant extra space.

// Example :

// Given the following binary tree,

//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7

// After calling your function, the tree should look like:

//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//  Definition for binary tree with next pointer.
  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
 
TreeLinkNode* nextRight(TreeLinkNode* current)
{
    TreeLinkNode* currNext = current->next;
    
    while (currNext!=NULL)
    {
        if (currNext->left)
            return currNext->left;
        else if (currNext->right)
            return currNext->right;
        currNext = currNext->next;
    }
    return NULL;
}

void Solution::connect(TreeLinkNode* A) {
    if (A==NULL)
        return;
    A->next = NULL;
    while (A!=NULL)
    {
        TreeLinkNode* B = A;
        while (B!=NULL)
        {
            if (B->left!=NULL)
            {
                if (B->right!=NULL)
                    B->left->next = B->right;
                else
                    B->left->next = nextRight(B);
            }
            if (B->right!=NULL)
                B->right->next = nextRight(B);
                
            B = B->next;
        }
        if (A->left!=NULL)
            A = A->left;
        else if (A->right!=NULL)
            A = A->right;
        else
            A = nextRight(A);
    }
}