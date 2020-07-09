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

int maxDepth(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    else{
        return 1+max(maxDepth(A->left),maxDepth(A->right));
    }
}
