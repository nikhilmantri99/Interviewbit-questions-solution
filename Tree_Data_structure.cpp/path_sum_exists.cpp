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

//We follow the free memory approach in order to avoid recursion reaching memory limit

bool path_exists(TreeNode *A,int sum){
    TreeNode *p,*q;
    if(A==NULL && sum==0){
        return true;
    }
    else if(A==NULL && sum!=0){
        return false;   
    }
    else if(A->left==NULL && A->right!=NULL){
        p=A->right;
        int temp=A->val;
        free(A);
        return path_exists(p,sum-temp);
    }
    else if(A->right==NULL && A->left!=NULL){
        p=A->left;
        int temp=A->val;
        free(A);
        return path_exists(p,sum-temp);
    }
    else{
        p=A->left;
        q=A->right;
        int temp=A->val;
        free(A);
        return path_exists(p,sum-temp) || path_exists(q,sum-temp);
    }
    return false;
} 
 
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A==NULL) return 0;
    bool truth=path_exists(A,B);
    if(truth==true){
        return 1;
    }
    else{
        return 0;
    }
    
}