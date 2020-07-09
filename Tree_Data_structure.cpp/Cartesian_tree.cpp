#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// * Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *construct(vector <int> &A, int left, int right){
    if(left>right){
        return NULL;
    }
    int max_index,j,k;
    max_index=left;
    for(j=left+1;j<=right;j++){
        if(A[j]>A[max_index]){
            max_index=j;
        }
    }
    TreeNode *root=NULL;
    root=new TreeNode(A[max_index]);
    root->left=construct(A,left,max_index-1);
    root->right=construct(A,max_index+1,right);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    TreeNode *root=NULL;
    root=construct(A,0,(int)(A.size())-1);
    return root;
}