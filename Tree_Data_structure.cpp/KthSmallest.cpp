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

int kthsmallest(TreeNode* A, int B) {//this is nothing nut in order travesal's non-recursive version. very useful
    stack <TreeNode *> s;
    TreeNode *p=A;
    while(p!=NULL){
        s.push(p);
        p=p->left;
    }
    int count=1;
    while(s.empty()==false){
        if(count==B){
            return s.top()->val;
        }
        p=s.top()->right;
        s.pop();
        while(p!=NULL){
            s.push(p);
            p=p->left;
        }
        count++;
    }
    return 0;
}


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


int main(){
    vector <int> A={11,2,3,5,6,0,1,8,17};
    int K=5;
    TreeNode *root=NULL;
    for(int i=0;i<A.size();i++){
        root=Insert(root,A[i]);
    }
    cout<<kthsmallest(root,K)<<endl;
    return 0;
}