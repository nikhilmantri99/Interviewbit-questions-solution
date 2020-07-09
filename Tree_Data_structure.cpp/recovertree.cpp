#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//  Two elements of a binary search tree (BST) are swapped by mistake.
//  Tell us the 2 values swapping which the tree will be restored.

//  efficient way:
//  The inorder traversal of a BST produces a sorted array. So a simple method is to store inorder traversal 
//  of the input tree in an auxiliary array. Sort the auxiliary array. Finally, insert the auxiilary array elements
//  back to the BST, keeping the structure of the BST same. Time complexity of this method is O(nLogn) and auxiliary
//  space needed is O(n).
//  We can solve this in O(n) time and with a single traversal of the given BST. Since inorder
//  traversal of BST is always a sorted array, the problem can be reduced to a problem where two elements of a 
//  sorted array are swapped. There are two cases that we need to handle:
//  1. The swapped nodes are not adjacent in the inorder traversal of the BST.
//  For example, Nodes 5 and 25 are swapped in {3 5 7 8 10 15 20 25}. 
//  The inorder traversal of the given tree is 3 25 7 8 10 15 20 5 
//  If we observe carefully, during inorder traversal, we find node 7 is smaller than the previous visited node 25.
//  Here save the context of node 25 (previous node). Again, we find that node 5 is smaller than the previous node 20. 
    //This time, we save the context of node 5 ( current node ). Finally swap the two node’s values.
//  2. The swapped nodes are adjacent in the inorder traversal of BST.
//   For example, Nodes 7 and 8 are swapped in {3 5 7 8 10 15 20 25}. 
//   The inorder traversal of the given tree is 3 5 8 7 10 15 20 25 
//  Unlike case #1, here only one point exists where a node value is smaller than previous node value. e.g. node
//  7 is smaller than node 8.
//  How to Solve? We will maintain three pointers, first, middle and last. When we find the first
//  point where current node value is smaller than previous node value, we update the first with the previous
//  node & middle with the current node. When we find the second point where current node value is smaller
//  than previous node value, we update the last with the current node. In case #2, we will never 
//  find the second point. So, last pointer will not be updated. After processing, if the last node value
//  is null, then two swapped nodes of BST are adjacent.  

//  Definition for binary tree


class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    void inorder(){
        stack <TreeNode *> s;
        TreeNode *p,*q,*r;
        p=this;
        while(p!=NULL){
            s.push(p);
            p=p->left;
        }
        while(!s.empty()){
            cout<<"inorder: "<<s.top()->val<<endl;
            p=s.top()->right;
            s.pop();
            while(p!=NULL){
                s.push(p);
                p=p->left;
            }
        }
    }

    int maxdepth(){
        if(this->left==NULL && this->right==NULL){
            return 1;
        }
        else if(this->left!=NULL && this->right==NULL){
            return 1+this->left->maxdepth();
        }
        else if(this->left==NULL && this->right!=NULL){
            return 1+this->right->maxdepth();
        }
        else{
            return 1+max(this->left->maxdepth(),this->right->maxdepth());
        }
    }
};

vector<int> recoverTree(TreeNode* A) {
    TreeNode *p,*q,*prev=NULL,*curr=NULL,*first=NULL,*middle=NULL,*last=NULL;
    p=A;
    stack <TreeNode *> s;
    vector <int> ans;
    if(A==NULL || (A->left==NULL && A->right==NULL)){
        return ans;
    }
    while(p!=NULL){
        s.push(p);
        p=p->left;
    }
    while(!s.empty()){
        if(prev==NULL){
            prev=s.top();
        }
        else{
            if(prev->val>s.top()->val){
                if(first==NULL){
                    first=prev;
                    middle=s.top();
                }
                else{
                    last=s.top();
                }
            }
            prev=s.top();
        }
        p=s.top()->right;
        s.pop();
        while(p!=NULL){
            s.push(p);
            p=p->left;
        }
    }
    if(last==NULL){
        ans.push_back(first->val);
        ans.push_back(middle->val);
    }
    else{
        ans.push_back(first->val);
        ans.push_back(last->val);
    }
    return ans;
}

int main(){
    TreeNode *root = new TreeNode(6); 
    root->left        = new TreeNode(10); 
    root->right       = new TreeNode(2); 
    root->left->left  = new TreeNode(1); 
    root->left->right = new TreeNode(3); 
    root->right->right = new TreeNode(12); 
    root->right->left = new TreeNode(7);
    root->inorder();
    vector <int> ans=recoverTree(root);
    cout<<"ans: "<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}