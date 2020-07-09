#include <bits/stdc++.h>
#include <iostream>
using namespace std;


//Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector <vector <int>> ans;
    queue <TreeNode *> qparent;
    qparent.push(A);
    while(qparent.empty()==false){
        vector <int> temp;
        queue <TreeNode *> qchild;
        while(qparent.empty()==false){
            temp.push_back(qparent.front()->val);
            if (qparent.front()->left!=NULL){
                qchild.push(qparent.front()->left);
            }
            if(qparent.front()->right!=NULL){
                qchild.push(qparent.front()->right);
            }
            qparent.pop();
        }
        if(temp.size()!=0){
            ans.push_back(temp);
        }
        qparent=qchild;
    }
    return ans;
}
