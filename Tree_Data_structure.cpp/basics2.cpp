#include <bits/stdc++.h>
#include <iostream>

using namespace std;
 
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

// 1. Push root to first stack.
// 2. Loop while first stack is not empty
//   2.1 Pop a node from first stack and push it to second stack
//   2.2 Push left and right children of the popped node to first stack
// 3. Print contents of second stack

vector<int> postorderTraversal(TreeNode* A) {
    vector <int> ans;
    if(A==NULL){
        return ans;
    }
    stack <TreeNode *> s;
    TreeNode *p,*q,*r;
    p=A;
    s.push(p);
    while(!s.empty()){
        p=s.top();
        ans.push_back(p->val);
        s.pop();
        q=p->left;
        r=p->right;
        if(q!=NULL){
            s.push(q);
        }
        if(r!=NULL){
            s.push(r);
        }
    }
    reverse(ans.begin(),ans.end());//we used array instead of second stack ans hence need to reverse it.
    return ans;
}

bool aresame(TreeNode *A,TreeNode *B){
    if(A==NULL && B==NULL){
        return true;
    }
    else if(A==NULL && B!=NULL){
        return false;
    }
    else if(A!=NULL && B==NULL){
        return false;
    }
    else if(A!=NULL && B!=NULL){
        if(A->val!=B->val){
            return false;
        }
        bool truth1=aresame(A->left,B->left);
        bool truth2=aresame(A->right,B->right);
        return (truth1 && truth2);
    }
}

TreeNode *insert(TreeNode *A, int x){
	if(A==NULL){
		return new TreeNode(x);
	}
	else{
		//greater than equal to goes in right subtree
		if(x>=A->val){
			A->right=insert(A->right,x);
		}
		else{
			A->left=insert(A->left,x);
		}
	}
}

//three cases to take care before deleting. First find the node recursively.
//1. if the node has no children, directly return NULL.
//2. if the node has one child, pull that child up in place of the root.
//3. if the node has two children, exchange the current node's val with the inorder successor, and delete the indorder sucessor.   

TreeNode *deletenode(TreeNode *A, int x){
	if(A==NULL){
		return NULL;
	}
	else if(x>A->val){
		A->right=deletenode(A->right,x);
	}
	else if(x<A->val){
		A->left=deletenode(A->left,x);
	}
	else if(x==A->val){
		if(A->left==NULL && A->right==NULL){
			return NULL;
		}
		else if(A->left!=NULL && A->right==NULL){
			A->left=deletenode(A->left,x);
			return A->left;
		}
		else if(A->left==NULL && A->right!=NULL){
			A->right=deletenode(A->right,x);
			return A->right;
		}
		TreeNode *p,*q,*r;
		p=A->right;
		p=deletenode(p,x);
		if(p==NULL){
			return A->left;
		}
		if(p->left==NULL){
			int temp=A->val;
			A->val=p->val;
			p->val=temp;
			A->right=deletenode(A->right,x);
			return A;
		}
		while(p->left!=NULL){
			p=p->left;
		}
		int temp=A->val;
		A->val=p->val;
		p->val=temp;
		A->right=deletenode(A->right,x);
		return A;
	}
}

int main(){
	TreeNode *root=NULL,*p,*q,*r;
	root=insert(root,5);
	root=insert(root,5);
	root=insert(root,2);
	root=insert(root,3);
	root=insert(root,1);
	root=insert(root,7);
	root=insert(root,6);
	//root->inorder();
	cout<<root->maxdepth()<<endl;
	return 0;
}