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

int height_of_tree(TreeNode *A){
    if(A==NULL){
        return 0;
    }
    else{
        return 1+max(height_of_tree(A->left),height_of_tree(A->right));
    }
}