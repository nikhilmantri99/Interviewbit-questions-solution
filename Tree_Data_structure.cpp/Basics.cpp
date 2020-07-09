#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Tree_node{
	int data;
	Tree_node *left;
	Tree_node *right;
	Tree_node (int x){
		this->data=x;
		this->left=NULL;
		this->right=NULL;
	}
};


bool isValid(Tree_node *A,int minval,int maxval){
    if(A==NULL){
        return true;
    }
    else if(A->data>=maxval || A->data<=minval){//strict binary tree
        return false;
    }
    else{
    	//need to carry the min and max value down the subtree
        return isValid(A->left,minval,min(A->data,maxval)) && isValid(A->right,max(A->data,minval),maxval);  
    }
}
 
int isValidBST(Tree_node* A) {
    bool truth=isValid(A,INT_MIN,INT_MAX);
    if(truth==false){
        return 0;
    }
    if(truth==true){
        return 1;
    }
}


void In_order_print(Tree_node *root){
	if(root==NULL){
		return;
	}
	In_order_print(root->left);
	cout<<root->data<<" ";
	In_order_print(root->right);
	return;
}

void Pre_order_print(Tree_node *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	Pre_order_print(root->left);
	Pre_order_print(root->right);
	return;
}

void Post_order_print(Tree_node *root){
	if(root==NULL){
		return;
	}
	Post_order_print(root->left);
	Post_order_print(root->right);
	cout<<root->data<<" ";
	return;
}


Tree_node* Insert(Tree_node *root,int x){
	if(root==NULL){
		return new Tree_node(x);
	}
	else{
		if(root->data<=x){
			root->right=Insert(root->right,x);
		}
		else{
			root->left=Insert(root->left,x);
		}
	}
	return root;
}

Tree_node * deleteNode(Tree_node *root, int x){
	if(root==NULL){
		return NULL;
	}
	if(root->data<x){
		root->right=deleteNode(root->right,x);
	}
	else if(root->data>x){
		root->left=deleteNode(root->left,x);
	}
	else if(root->data==x){
		if(root->left==NULL && root->right==NULL){
			return NULL;
		}
		else if(root->left!=NULL && root->right==NULL){
			return root->left;
		}
		else if(root->right!=NULL && root->left==NULL){
			return root->right;
		}
		else if(root->right!=NULL && root->left!=NULL){
			Tree_node *p;
			p=root->right;
			while(p->left!=NULL){
				p=p->left;
			}
			int temp=p->data;
			p->data=root->data;
			root->data=temp;
			root->right=deleteNode(root->right,x);
		}
	}
	cout<<endl;
	return root;
}

void inorder_successor_stack(Tree_node *A){
	stack <Tree_node*> s;
	Tree_node *p=A;
	while(p!=NULL){
		s.push(p);
		p=p->left;
	}
	while(s.empty()==false){
		cout<<s.top()->data<<" ";
		p=s.top()->right;
		s.pop();
		while(p!=NULL){
			s.push(p);
			p=p->left;
		}
	}
	cout<<endl;
	return ;
}



int inorder_successor_stack_value(Tree_node *A,int x){
	stack <Tree_node*> s;
	Tree_node *p=A;
	while(p!=NULL){
		s.push(p);
		p=p->left;
	}
	int flag=0,next_value=-1;
	while(s.empty()==false){
		if(flag==1){
			next_value=s.top()->data;
			flag--;
		}
		if(s.top()->data==x){
			flag++;
		}
		//cout<<s.top()->data<<" ";
		p=s.top()->right;
		s.pop();
		while(p!=NULL){
			s.push(p);
			p=p->left;
		}
	}
	cout<<"required next value: "<<next_value<<endl;
	return next_value;
}

int main(){
	vector <int> A={11, 2, 9, 13, 57, 25, 1, 1, 90, 3};
	Tree_node *root=NULL;
	for(int i=0;i<A.size();i++){
		cout<<"i: "<<i<<endl;
		root=Insert(root,A[i]);
	}
	inorder_successor_stack(root);
	In_order_print(root);
	cout<<inorder_successor_stack_value(root,9)<<endl;
	cout<<endl;
	root=deleteNode(root,11);
	In_order_print(root);
	cout<<endl;	
	Pre_order_print(root);
	cout<<endl;
	Post_order_print(root);
	cout<<endl;
	
	return 0;
}