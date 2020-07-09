#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// Let us see the process of constructing tree from in[] = {4, 8, 2, 5, 1, 6, 3, 7} and post[] = {8, 4, 5, 2, 6, 7, 3, 1}

// 1) We first find the last node in post[]. The last node is “1”, we know this value is root as root always appear in the end of postorder traversal.

// 2) We search “1” in in[] to find left and right subtrees of root. Everything on left of “1” in in[] is in left subtree and everything on right is in right subtree.

//          1
//        /    \
// [4, 8, 2, 5]   [6, 3, 7] 

// 3) We recur the above process for following two.
// ….b) Recur for in[] = {6, 3, 7} and post[] = {6, 7, 3}
// …….Make the created tree as right child of root.
// ….a) Recur for in[] = {4, 8, 2, 5} and post[] = {8, 4, 5, 2}.
// …….Make the created tree as left child of root.

// Below is the implementation of above idea. One important observation is, we recursively call for right subtree before left subtree as we decrease index of postorder index whenever we create a new node.

//we use the postorder to find root, locate it in inorder, then whatever is to right of this goes in right subtree and whatever is to left
//goes in left subtree. we use hashmap to map every inroder element to its index in inorder. and we go from back to front
//in postorder collecting roots, we resucrsively call root->right first, as root->right comes first from back in postorder
//before left;

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
};

 
TreeNode *construct(vector <int> &in,vector <int> &post,unordered_map<int,int> &inmap,int left, int right,int &postindex){
    if(left>right){
        return NULL;
    }
    int i=inmap[post[postindex]];
    int val=post[postindex];
    if(i>right || i<left){
        return NULL;
    }
    TreeNode *root= new TreeNode(val);
    postindex--;
    root->right=construct(in,post,inmap,i+1,right,postindex);
    root->left=construct(in,post,inmap,left,i-1,postindex);
    return root;
}
 
TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    int i,j,k;
    unordered_map <int,int> inmap;
    for(i=0;i<A.size();i++){
        inmap[A[i]]=i;
    }
    int postindex=B.size()-1;
    return construct(A,B,inmap,0,A.size()-1,postindex);
}

int main(){
    vector <int> in={2, 1, 3};
    vector <int> post={2, 3, 1};
    TreeNode *root=buildTree(in,post);
    root->inorder();
    return 0;
}