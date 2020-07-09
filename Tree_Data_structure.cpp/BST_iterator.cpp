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
 
stack <TreeNode *> s;

BSTIterator::BSTIterator(TreeNode *root) {
    while(!s.empty()){
        s.pop();
    }
    TreeNode *p;
    p=root;
    while(p!=NULL){
        s.push(p);
        p=p->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(s.empty()){
        return false;
    }
    else{
        return true;
    }
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *p,*q;
    p=s.top();
    s.pop();
    q=p->right;
    while(q!=NULL){
        s.push(q);
        q=q->left;
    }
    return p->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
