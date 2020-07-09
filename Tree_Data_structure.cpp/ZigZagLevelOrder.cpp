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

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    int i=0;
    vector<vector<int>> ans;
    vector <int> temp;
    deque <TreeNode *> dq;
    dq.push_front(A);
    int count=1;
    while(dq.empty()==false){
        temp.clear();
        deque <TreeNode *> dq2;
        while(dq.empty()==false){
            if(i%2==0){
                //left to right print
                TreeNode *p=dq.front();
                temp.push_back(p->val);
                dq.pop_front();
                if(p->left!=NULL){
                    dq2.push_front(p->left);
                }
                if(p->right!=NULL){
                    dq2.push_front(p->right);
                }
            }
            if(i%2==1){
                TreeNode *p=dq.front();
                temp.push_back(p->val);
                dq.pop_front();
                if(p->right!=NULL){
                    dq2.push_front(p->right);
                }
                if(p->left!=NULL){
                    dq2.push_front(p->left);
                }
            }
        }
        ans.push_back(temp);
        i++;
        dq=dq2;
    }
    return ans;
}