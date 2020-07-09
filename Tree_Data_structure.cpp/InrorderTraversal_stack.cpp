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

vector<int> inorderTraversal(TreeNode* A){
    vector <int> ans;
    stack <TreeNode *> s;
    TreeNode *p;
    p=A;
    while(p!=NULL){
        s.push(p);
        p=p->left;
    }
    while(s.empty()==false){
        ans.push_back(s.top()->val);
        p=s.top()->right;
        s.pop();
        while(p!=NULL){
            s.push(p);
            p=p->left;
        }
    }
    return ans;
}