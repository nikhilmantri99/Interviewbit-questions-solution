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

TreeNode* Insert(TreeNode *root,int x){
    if(root==NULL){
        return new TreeNode(x);
    }
    else{
        if(root->val<=x){
            root->right=Insert(root->right,x);
        }
        else{
            root->left=Insert(root->left,x);
        }
    }
    return root;
}

bool IsThisSymmetric(TreeNode *A_left,TreeNode*A_right){
    if(A_right == NULL && A_left==NULL){
        return true;
    }
    else if((A_left!=NULL && A_right==NULL)||(A_right!=NULL && A_left==NULL)){
        return false;
    }
    else if(A_left->val!=A_right->val){
        return false;
    }
    else{
        return IsThisSymmetric(A_left->left,A_right->right) && IsThisSymmetric(A_left->right,A_right->left);//crucial visualization
    }
}
 
int isSymmetric(TreeNode* A) {
    if(A==NULL){
        return 1;
    }
    bool truth=IsThisSymmetric(A->left,A->right);
    if(truth==true){
        return 1;
    }
    else{
        return 0;
    }
}