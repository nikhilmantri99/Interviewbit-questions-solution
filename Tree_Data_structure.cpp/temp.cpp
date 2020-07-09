#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Tree_node{
    int data;
    Tree_node *left;
    Tree_node *right;
    Tree_node (int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};

int Solution::isValidBST(TreeNode* A) {
    if(A==NULL){
        return 1;
    }
    else if(A->left==NULL && A->right==NULL){
        return 1;
    }
    else if(A->left!=NULL && A->right==NULL){
        if(A->left->val>A->data){
            return 0;
        }
        else{
            return isValidBST(A->left);
        }
    }
    else if(A->right!=NULL && A->left==NULL){
        if(A->right->data<A->data){
            return 0;
        }
        else{
            return isValidBST(A->right);
        }
    }
    else{
        
    }
}