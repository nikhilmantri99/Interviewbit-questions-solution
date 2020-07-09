#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Find the lowest common ancestor in an unordered binary tree given two values in the tree.
// Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or
// directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 

//Okay so the tree is unordered binary tree. Here what we do is we first find whether both the nodes exist
// in the tree or not. we create a bool function for that. In the process we also fill a stack consisting of ancestors
// of the node to be found in other words, the nodes in line showcasing the way to reach the desired nodes.
// we will have two such stacks. now we pop one of the stacks (the greater size one) until both the stacks
//reach the same size. then we pop them together until we find a node that is common to both stacks, thus this is the 
//least common ancestor.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool find_with_stack(TreeNode *A, stack <TreeNode*> &s,int x){
    if(A->val!=x && A->left==NULL && A->right==NULL){
        return false;
    }
    if(A->val==x){
        return true;
    }
    if(A->left!=NULL){
        s.push(A->left);
        bool truth=find_with_stack(A->left,s,x);
        if(truth==true){
            return true;
        }
        s.pop();
    }
    if(A->right!=NULL){
        s.push(A->right);
        bool truth=find_with_stack(A->right,s,x);
        if(truth==true){
            return true;
        }
        s.pop();
    }
    return false;
}

int Solution::lca(TreeNode* A, int B, int C) {
    if(A==NULL){
        return -1;
    }
    stack <TreeNode *> sB;
    stack <TreeNode *> sC;
    sB.push(A);
    sC.push(A);
    bool truth1=find_with_stack(A,sB,B);
    bool truth2=find_with_stack(A,sC,C);
    if(truth1==false){
        return -1;
    }
    else if(truth2==false){
        return -1;
    }
    while(sB.top()!=sC.top()){
        if(sB.size()>sC.size()){
            sB.pop();
        }
        else if(sB.size()<sC.size()){
            sC.pop();
        }
        else{
            sB.pop();
            sC.pop();
        }
    }
    return sB.top()->val;
}
