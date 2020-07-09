#include <bits/stdc++.h>
#include <iostream>

using namespace std;
///Question///
// Given a binary tree

//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

//     Note:

//         You may only use constant extra space.

// Example :

// Given the following binary tree,

//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7

// After calling your function, the tree should look like:

//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL

//     Note 1: that using recursion has memory overhead and does not qualify for constant space.
//     Note 2: The tree need not be a perfect binary tree. 

//Have you tried making use of the next links you are creating ? Yes everytime we can head down the level and using current
//next pointers we can set the next pointers of the children nodes of the current level nodes. 
//Also we can head down a level using these next pointers. Go to next node such that it has at least one child.
// and then for the next level creation head down to that node. See the code for clarity.



//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
 
void connect(TreeLinkNode* A) {
    TreeLinkNode *mark=A,*p=NULL,*q=NULL,*r=NULL;
    while(mark!=NULL){
        q=mark;
        p=NULL;
        while(q!=NULL){
            if(p!=NULL){
                if(q->left!=NULL){
                    p->next=q->left;
                }
                else if(q->right!=NULL){
                    p->next=q->right;
                }
            }
            if(q->left!=NULL && q->right!=NULL){
                q->left->next=q->right;
                p=q->right;
            }
            else if(q->left!=NULL && q->right==NULL){
                p=q->left;
            }
            else if(q->left==NULL && q->right!=NULL){
                p=q->right;
            }
            q=q->next;
        }
        while(mark!=NULL && mark->left==NULL && mark->right==NULL){
            mark=mark->next;
        }
        if(mark==NULL){
            break;
        }
        else if(mark!=NULL && mark->left!=NULL){
            mark=mark->left;
        }
        else if(mark!=NULL && mark->right!=NULL){
            mark=mark->right;
        }
    }
}