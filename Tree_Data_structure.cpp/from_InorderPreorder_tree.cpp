#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// 1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) 
//	  to pick next element in next recursive call.
// 2) Create a new tree node tNode with the data as picked element.
// 3) Find the picked element’s index in Inorder. Let the index be inIndex.
// 4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
// 5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
// 6) return tNode


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

TreeNode * construct(unordered_map <int,int> &umap,vector <int> &Inorder, vector <int> &Preorder, int &preIndex, int Inorderleft, int Inorderright){
	if(Inorderleft>Inorderright){
		return NULL;
	}
	if(preIndex>=Preorder.size()){
		return NULL;
	}
	TreeNode *root;
	int mark=umap[Preorder[preIndex]];
	root=new TreeNode(Preorder[preIndex]);
	preIndex++;
	root->left=construct(umap,Inorder,Preorder,preIndex,Inorderleft,mark-1);
	root->right=construct(umap,Inorder,Preorder,preIndex,mark+1,Inorderright);
	return root;
}

TreeNode* buildTree(vector<int> &A/*pre order*/, vector<int> &B/*In order*/) {
	unordered_map <int,int> umap;//inorder indexes as an ordered map so that no need to search
	for(int i=0;i<A.size();i++){
		umap[B[i]]=i;
	}
	int preIndex=0;
	TreeNode *root=construct(umap,B,A,preIndex,0,B.size()-1);
	return root;
}

void In_order_print(TreeNode *root){
	if(root==NULL){
		return;
	}
	In_order_print(root->left);
	cout<<root->val<<" ";
	In_order_print(root->right);
	return;
}

void Pre_order_print(TreeNode *root){
	if(root==NULL){
		return;
	}
	cout<<root->val<<" ";
	Pre_order_print(root->left);
	Pre_order_print(root->right);
	return;
}

int main(){
	vector <int> Pre={1, 2, 3};
	vector <int> In={2,1,3};
	TreeNode *root=buildTree(Pre,In);
	cout<<"Preorder:"<<endl;
	Pre_order_print(root);
	cout<<endl;
	cout<<"Inorder: "<<endl;
	In_order_print(root);
	cout<<endl;
}
