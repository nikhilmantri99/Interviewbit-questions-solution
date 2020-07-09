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


vector<int> preorderTraversal(TreeNode* A) {
    vector <int> ans;
    stack <TreeNode *> s;
    TreeNode *p=A;
    while(p!=NULL){
        ans.push_back(p->val);
        s.push(p);
        p=p->left;
    }
    while(s.empty()==false){
        p=s.top()->right;
        s.pop();
        while(p!=NULL){
            ans.push_back(p->val);
            s.push(p);
            p=p->left;
        }
    }
    return ans;
}

