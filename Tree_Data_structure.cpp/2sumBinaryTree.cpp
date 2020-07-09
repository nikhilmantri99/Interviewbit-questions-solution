#include <bits/stdc++.h>
#include <iostream>

using namespace std;

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

int Solution::t2Sum(TreeNode* A, int B) {
    if(A==NULL || (A->left==NULL && A->right==NULL)){
        return 0;
    }
    A=Btree2DLL(A);
    //print_list(A);
    TreeNode *p,*q,*r;
    p=A;
    while(p->right!=NULL){
        p=p->right;
    }
    r=p;//last node
    p=A;//first node
    while(p!=r){
        if(p->val+r->val==B){
            return 1;
        }
        else if(p->val + r->val<B){
            p=p->right;
        }
        else{
            r=r->left;
        }
    }
    return 0;
}


















