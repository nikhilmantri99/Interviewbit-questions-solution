#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x){
		this->data=x;
		this->left=NULL;
		this->right=NULL;
	}
};


void In_order_print(TreeNode *root){
	if(root==NULL){
		return;
	}
	In_order_print(root->left);
	cout<<root->data<<" ";
	In_order_print(root->right);
	return;
}

TreeNode* build_tree(TreeNode *root,const vector<int> &A,int left, int right){
    if(left>right){
        return NULL;
    }
    int mid=(left+right)/2;
    root = new TreeNode(A[mid]);
    root->left=build_tree(root->left,A,left,mid-1);
    root->right=build_tree(root->right,A,mid+1,right);
    return root;
} 

TreeNode* sortedArrayToBST(const vector<int> &A) {
    TreeNode *root=build_tree(root,A,0,A.size()-1);
    return root;
}

int main(){
	vector <int> A={1,2,3};
	TreeNode *root=sortedArrayToBST(A);
	In_order_print(root);
	cout<<endl;
	return 0;
}