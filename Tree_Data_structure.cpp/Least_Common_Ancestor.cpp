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

void isTargetPresent(bool &truth,TreeNode *A, int target, stack <TreeNode*> &s,stack <TreeNode*> &ans){//to create a stack of ancestors ans search for the target if present
    if(A==NULL){
        s.push(A);
        return;
    }
    s.push(A);
    if(A->val==target){
        ans=s;
        truth=true;
        return;
    }
    isTargetPresent(truth,A->left,target,s,ans);
    s.pop();
    isTargetPresent(truth,A->right,target,s,ans);
    s.pop();
}

void reconstruct_path(stack <TreeNode*> s,int target){
    cout<<"Path for "<<target<<" :"<<endl;
    while(s.empty()==false){
        cout<<s.top()->val<<" ";
        s.pop();
    }
    cout<<endl;
}

int Solution::lca(TreeNode* A, int B, int C) {
    stack <TreeNode*> sB,tempB;
    stack <TreeNode*> sC,tempC;
    
    bool checkB=false,checkC=false;
    
    isTargetPresent(checkB,A,B,tempB,sB);
    isTargetPresent(checkC,A,C,tempC,sC);
    
    if(checkB==false||checkC==false){
        return -1;
    }
    
    // reconstruct_path(sB,B);
    // reconstruct_path(sC,C);
    
    if(sB.size()>sC.size()){
        while(sB.size()!=sC.size()){
            sB.pop();
        }
    }
    
    if(sC.size()>sB.size()){
        while(sC.size()!=sB.size()){
            sC.pop();
        }
    }
    
    while(sC.top()!=sB.top()){
        sC.pop();
        sB.pop();
    }
    if(sC.empty()){
        return -1;
    }
    return sC.top()->val;
    

}
