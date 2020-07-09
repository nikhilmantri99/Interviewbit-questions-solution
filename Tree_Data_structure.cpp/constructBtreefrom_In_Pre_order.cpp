#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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

// In a Preorder sequence, leftmost element is the root of the tree. So we know ‘A’ is root for given sequences.
 // By searching ‘A’ in Inorder sequence, we can find out all elements on left side of ‘A’ are in left subtree and 
 // elements on right are in right subtree. So we know below structure now.
//                  A
//                /   \
//              /       \
//            D B E     F C

// We recursively follow above steps and get the following tree.

//          A
//        /   \
//      /       \
//     B         C
//    / \        /
//  /     \    /
// D       E  F

// Algorithm: buildTree()
// 1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) 
//to pick next element in next recursive call.
// 2) Create a new tree node tNode with the data as picked element.
// 3) Find the picked element’s index in Inorder. Let the index be inIndex.
// 4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
// 5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
// 6) return tNode.

// Time Complexity: O(n^2). Worst case occurs when tree is left skewed. Example Preorder and Inorder traversals 
// for worst case are {A, B, C, D} and {D, C, B, A}.
// Efficient Approach :
// We can optimize the above solution using hashing (unordered_map in C++ or HashMap in Java). We store
// indexes of inorder traversal in a hash table. So that search can be done O(1) time.

TreeNode *construct(vector <int> &pre,vector <int> &in, unordered_map <int,int> &inmap,int left, int right, int &preindex){
    if(left>right){
        return NULL;
    }
    int i=inmap[pre[preindex]];
    int val=pre[preindex];
    if(i<left||i>right){
        return NULL;
    }
    TreeNode *root=new TreeNode(val);
    preindex++;
    root->left=construct(pre,in,inmap,left,i-1,preindex);
    root->right=construct(pre,in,inmap,i+1,right,preindex);
    return root;
}
 
TreeNode* buildTree(vector<int> &A, vector<int> &B){
    int i,j,k;
    unordered_map <int,int> inmap;
    for(i=0;i<B.size();i++){
        inmap[B[i]]=i;
    }
    int preindex=0;
    return construct(A,B,inmap,0,A.size()-1,preindex);
}

int main(){
	vector <int> A={1, 2, 3};
	vector <int> B={2, 1, 3};
	TreeNode *root=buildTree(A,B);
	root->inorder();
	return 0;
}