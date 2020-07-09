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

// We have already discussed construction of tree from Inorder and Preorder traversals. The idea is similar.
// Let us see the process of constructing tree from in[] = {4, 8, 2, 5, 1, 6, 3, 7} and post[] = {8, 4, 5, 2, 6, 7, 3, 1}
// 1) We first find the last node in post[]. The last node is “1”, 
//we know this value is root as root always appear in the end of postorder traversal.
// 2) We search “1” in in[] to find left and right subtrees of root.
// Everything on left of “1” in in[] is in left subtree and everything on right is in right subtree.
//          1
//        /    \
// [4, 8, 2, 5]   [6, 3, 7] 
// 3) We recur the above process for following two.
// ….b) Recur for in[] = {6, 3, 7} and post[] = {6, 7, 3}
// …….Make the created tree as right child of root.
// ….a) Recur for in[] = {4, 8, 2, 5} and post[] = {8, 4, 5, 2}.
// …….Make the created tree as left child of root.
// Below is the implementation of above idea. One important observation is, 
// We recursively call for right subtree before left subtree as we decrease index of postorder index whenever we create a new node.

void In_order_print(TreeNode *root){
	if(root==NULL){
		return;
	}
	In_order_print(root->left);
	cout<<root->val<<" ";
	In_order_print(root->right);
	return;
}

void Post_order_print(TreeNode *root){
	if(root==NULL){
		return;
	}
	Post_order_print(root->left);
	Post_order_print(root->right);
	cout<<root->val<<" ";
	return;
}


//Last element of post order is root.Combining this info with INorder's left subtree first then root then right subtree order. 
TreeNode *construct(unordered_map <int,int> &umap,vector <int> &Inorder, vector<int> &Postorder, int &postIndex,int InorderLeft, int InorderRight){
	if(InorderLeft>InorderRight){
		return NULL;
	}
	if(postIndex<0){
		return NULL;
	}
	TreeNode *root;
	int mark=umap[Postorder[postIndex]];
	root=new TreeNode(Postorder[postIndex]);
	postIndex--;
	root->right=construct(umap,Inorder,Postorder,postIndex,mark+1,InorderRight);
	root->left=construct(umap,Inorder,Postorder,postIndex,InorderLeft,mark-1);
	return root;
}


TreeNode* buildTree(vector<int> &A/*Inorder*/, vector<int> &B/*Postorder*/) {
    unordered_map <int,int> umap;
    for(int i=0;i<A.size();i++){
    	umap[A[i]]=i;
    }
    int postIndex=A.size()-1;
    TreeNode *root=construct(umap,A,B,postIndex,0,A.size()-1);
    return root;
}

int main(){
	vector <int> In={2, 1, 3};
	vector <int> Post={2, 3, 1};
	TreeNode *root=buildTree(In,Post);
	cout<<"Inorder:";
	In_order_print(root);
	cout<<endl;
	cout<<"Postorder:";
	Post_order_print(root);
	cout<<endl;
	return 0;
}
