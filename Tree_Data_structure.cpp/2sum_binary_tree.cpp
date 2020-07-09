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



// Given a binary search tree T, 
//where each node contains a positive integer, and an integer K, 
//you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.
// Return 1 to denote that two such nodes exist. Return 0, otherwise.
// Notes
//     Your solution should run in linear time and not take memory more than O(height of T).
//     Assume all values in BST are distinct.

// We follow the approach as initiated by inorder traversal which gives elements in sorted order in a BST.
// in a sorted array we would start fromm extremes and if sum is less we increase left, if sum is more we decrease
// right till we get to the required value.
//We follow a similiar approach here. we maintain smallest and largest pointers like in inorder traversal without
//recursion. and thus proceed.



int return_largest(stack <TreeNode *> &large){
    int t=large.top()->val;
    TreeNode *q= large.top()->left;
    large.pop();
    while(q!=NULL){
        large.push(q);
        q=q->right;
    }
    return t;
}


int return_smallest(stack <TreeNode *> &small){
    int t=small.top()->val;
    TreeNode *q= small.top()->right;
    small.pop();
    while(q!=NULL){
        small.push(q);
        q=q->left;
    }
    return t;
}
 
int Solution::t2Sum(TreeNode* A, int B) {
    stack <TreeNode *> small;
    stack <TreeNode *> large;
    TreeNode *p;
    p=A;
    while(p!=NULL){
        small.push(p);
        p=p->left;
    }
    p=A;
    while(p!=NULL){
        large.push(p);
        p=p->right;
    }
    int l=return_smallest(small);
    int r=return_largest(large);
    while(l<r){
        if(l+r==B){
            return 1;
        }
        else if(l+r<B){
            l=return_smallest(small);
        }
        else{
            r=return_largest(large);
        }
    }
    return 0;
}