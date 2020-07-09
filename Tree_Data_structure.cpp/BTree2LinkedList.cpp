#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Given a binary tree, flatten it to a linked list in-place.
     //    1
     //    / \
     //   2   5
     //  / \   \
     // 3   4   6
    
    //The above thus becomes:
    
    // 1
    // \
    //  2
    //   \
    //    3
    //     \
    //      4
    //       \
    //        5
    //         \
    //          6

//

// If you notice carefully in the flattened tree, each node’s right child 
//points to the next node of a pre-order traversal.

// Now, if a node does not have left node, then our problem reduces to solving it for the node->right.
// If it does, then the next element in the preorder traversal is the
// immediate left child. But if we make the immediate left child as the right child of the node, 
//then the right subtree will be lost. So we figure out where the right subtree should go. 
//In the preorder traversal, the right subtree comes right after the rightmost element in the left subtree.
// So we figure out the rightmost element in the left subtree, and attach the right subtree as its right child. 
//We make the left child as the right child now and move on to the next node.


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

TreeNode* flatten(TreeNode* A){
    if(A==NULL){
        return A;
    }
    if(A->left==NULL && A->right==NULL){
        return A;
    }
    if(A->right!=NULL && A->left==NULL){
        A->right=flatten(A->right);
        return A;
    }
    if(A->left!=NULL && A->right==NULL){
        A->right=A->left;
        A->left=NULL;
        A->right=flatten(A->right);
        return A;
    }
    TreeNode *l,*p,*q;
    q=A->right;
    // q=flatten(q);
    A->left=flatten(A->left);
    p=A->left;
    if(p!=NULL){
        while(p->right!=NULL){
            p=p->right;
        }
        p->right=q;
        A->right=A->left;
        A->left=NULL;
    }
    A->right=flatten(A->right);
    return A;
}

int main(){
    TreeNode *root,*p;
    root =new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->right=new TreeNode(6);
    root=flatten(root);
    p=root;
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->right;
    }
    cout<<endl;
    return 0;
}