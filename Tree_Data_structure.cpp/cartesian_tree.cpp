#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Given an inorder traversal of a cartesian tree, construct the tree.

//     Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 

//     Note: You may assume that duplicates do not exist in the tree. 

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

TreeNode *construct(vector <int> &Inorder,int Inorderleft, int Inorderright){
    //cout<<"new call"<<endl;
    if(Inorderleft>Inorderright){
        return NULL;
    }
    int maxelem=Inorder[Inorderleft],maxIndex=Inorderleft;
    for(int i=Inorderleft+1;i<=Inorderright;i++){
        if(Inorder[i]>maxelem){
            maxelem=Inorder[i];
            maxIndex=i;
        }
    }
    TreeNode *root=new TreeNode(maxelem);
    root->left=construct(Inorder,Inorderleft,maxIndex-1);
    root->right=construct(Inorder,maxIndex+1,Inorderright);
    return root;
} 
 
TreeNode* Solution::buildTree(vector<int> &A) {
    TreeNode *root=construct(A,0,A.size()-1);
    return root;
}
