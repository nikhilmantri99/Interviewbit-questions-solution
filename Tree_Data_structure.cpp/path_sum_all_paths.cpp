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


void update_ans(vector<vector<int>>&ans,vector <int> &temp,TreeNode *A, int sum){
    int t;
    TreeNode *p,*q;
    //cout<<"Tatti"<<endl;
    if(A==NULL && sum==0){
        //cout<<"here4"<<endl;
        ans.push_back(temp);
        return;
    }
    else if(A==NULL && sum!=0){
        //cout<<"here3"<<endl;
        return ;
    }
    else if(A->left==NULL && A->right==NULL){//dont forget this case
        //cout<<"here-1"<<endl;
        t=A->val;
        free(A);
        temp.push_back(t);
        update_ans(ans,temp,NULL,sum-t);
        temp.erase(temp.end()-1);
    }
    else if(A->left!=NULL && A->right==NULL){
        //cout<<"here2"<<endl;
        t=A->val;
        p=A->left;
        free(A);
        temp.push_back(t);
        update_ans(ans,temp,p,sum-t);
        temp.erase(temp.end()-1);
    }
    else if(A->right!=NULL && A->left==NULL){
        //cout<<"here1"<<endl;
        t=A->val;
        p=A->right;
        free(A);
        temp.push_back(t);
        update_ans(ans,temp,p,sum-t);
        temp.erase(temp.end()-1);
    }
    else if(A->left!=NULL && A->right!=NULL){
        //cout<<"here"<<endl;
        t=A->val;
        p=A->left;
        q=A->right;
        free(A);
        temp.push_back(t);
        update_ans(ans,temp,p,sum-t);
        temp.erase(temp.end()-1);
        temp.push_back(t);
        update_ans(ans,temp,q,sum-t);
        temp.erase(temp.end()-1);
    }
    return;
}


vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {//will return a collection of all the paths; as a vector of vectors
    vector <vector<int>> ans;
    vector<int> temp;
    update_ans(ans,temp,A,B);
    return ans;
}