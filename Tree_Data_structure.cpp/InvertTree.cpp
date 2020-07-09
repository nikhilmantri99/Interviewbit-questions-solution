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

TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL) return A;
    TreeNode *p=A->left;
    A->left=A->right;
    A->right=p;
    A->left=invertTree(A->left);
    A->right=invertTree(A->right);
    return A;
}