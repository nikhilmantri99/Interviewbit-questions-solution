#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers 
// in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes 
// in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT)
//must be head node of the DLL.
//Suppose that we are needed to convert the tree to DLL in place and memory not more than  O(height of tree).
//we do this by using the stack method of inorder traversal. As the stack is filled, we just need to link the top element
// to the next element of the stack. Take a look you will know. The direct application of this is,
//in case of BST, we get a doubly linked list that is in sorted fashion. thus we can now search two elements with
//given sum in linear time , by two pointer method.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_list(TreeNode *A){
    TreeNode *p,*q,*r;
    p=A;
    while(p->right!=NULL){
        cout<<p->val<<"->";
        p=p->right;
    }
    cout<<p->val<<endl;
    r=p;
    while(r->left!=NULL){
        cout<<r->val<<"<-";
        r=r->left;
    }
    cout<<r->val<<endl;
}

TreeNode *Btree2DLL(TreeNode *A){
	if((A==NULL)||(A->left==NULL && A->right==NULL)){
		return A;
	}
	TreeNode *root=NULL,*p,*q,*r;
	stack <TreeNode *> s;
	p=A;
	while(p!=NULL){
		s.push(p);
		p=p->left;
	}
	int flag=0;
	while(!s.empty()){
		p=s.top();
		q=s.top()->right;
		s.pop();
		while(q!=NULL){
			s.push(q);
			q=q->left;
		}
		if(flag==0){
			root=p;
			flag++;
		}
		if(s.empty()){
			break;
		}
		p->right=s.top();
		s.top()->left=p;
	}
	return root;
}

int main(){
	TreeNode *root=new TreeNode(10);
	root->left= new TreeNode(12);
	root->left->left=new TreeNode(25);
	root->left->right=new TreeNode(30);
	root->right=new TreeNode(15);
	root->right->left=new TreeNode(36);
	root=Btree2DLL(root);
	print_list(root);
	return 0;
}