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


void update_ans(TreeNode *A, int &ans, int temp, int &M){
    if(A->left==NULL && A->right==NULL){
        //cout<<"here"<<endl;
        temp=((10*temp)%M+(A->val)%M)%M;
        //cout<<"temp: "<<temp<<endl;
        ans=((ans%M)+(temp%M))%M;
        //cout<<"ans :"<<ans<<endl; 
    }
    else if(A->left!=NULL && A->right==NULL){
        //cout<<"here2"<<endl;
        temp=((10*temp)%M+(A->val)%M)%M;
        //cout<<"temp: "<<temp<<endl;
        update_ans(A->left,ans,temp,M);
    }
    else if(A->right!=NULL && A->left==NULL){
        //cout<<"here3"<<endl;
        temp=((10*temp)%M+(A->val)%M)%M;
        //cout<<"temp: "<<temp<<endl;
        update_ans(A->right,ans,temp,M);
    }
    else if(A->left!=NULL && A->right!=NULL){
        //cout<<"here4"<<endl;
        temp=((10*temp)%M+(A->val)%M)%M;
        //cout<<"temp: "<<temp<<endl;
        update_ans(A->left,ans,temp,M);
        //cout<<"temp: "<<temp<<endl;
        update_ans(A->right,ans,temp,M);
    }
}  
 
int Solution::sumNumbers(TreeNode* A){
    int ans=0;
    int temp=0;
    int M=1003;
    update_ans(A,ans,temp,M);
    return ans%M;
}
