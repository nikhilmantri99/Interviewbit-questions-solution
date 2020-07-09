// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

//     NOTE : The path has to end on a leaf node. 

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x){
        this->val=x;
        this->left=NULL;
        this->right=NULL;
    }
};

int Solution::minDepth(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    else if(A->left==NULL && A->right!=NULL){//these two extra conditions because the path has to end on a leaf node with both arms null.
       return 1+minDepth(A->right);
    }
    else if(A->left!=NULL && A->right==NULL){
        return 1+minDepth(A->left);
    }
    else{
        return 1+min(minDepth(A->left),minDepth(A->right));
    }
}