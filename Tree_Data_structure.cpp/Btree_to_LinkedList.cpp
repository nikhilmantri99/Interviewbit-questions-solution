#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// Given a binary tree, flatten it to a linked list in-place.

// Example :
// Given


//          1
//         / \
//        2   5
//       / \   \
//      3   4   6

// The flattened tree should look like:

//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6

// Note that the left child of all nodes should be NULL.



// * Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//observe the given example.
// //put in simple words :
// 1. Flatten left and right child of the root node.
// 2. Then move to the rightmost node of the left child of the root. place the right child of the root,
// here. Then move this overall left child to right child place and Nullify left child. 

TreeNode* flatten(TreeNode* A) {
    if(A==NULL){
        return NULL;
    }
    else if(A->left==NULL && A->right==NULL){
        return A;
    }
    else if(A->left!=NULL && A->right==NULL){
        A->right=A->left;
        A->left=NULL;
        A->right=flatten(A->right);
        return A;
    }
    else if(A->left==NULL && A->right!=NULL){
        A->right=flatten(A->right);
        return A;
    }
    else{
        A->left=flatten(A->left);
        A->right=flatten(A->right);
        TreeNode *p,*q;
        p=A->left;
        while(p->right!=NULL){
            p=p->right;
        }
        p->right=A->right;
        A->right=NULL;
        A->right=A->left;
        A->left=NULL;
        return A;
    }
}
