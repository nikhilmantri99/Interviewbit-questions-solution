#include <bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *A){
	while(A!=NULL){
		cout<<A->val<<" ";
		A=A->next;
	}
	cout<<endl;
} 

ListNode *sorted_merge(ListNode *a, ListNode *b){
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}
	ListNode *ans=NULL,*p,*q,*t;
	if(a->val<=b->val){
		ans=a;
		a=a->next;
		ans->next=NULL;
	}
	else{
		ans=b;
		b=b->next;
		ans->next=NULL;
	}
	t=ans;
	p=a;
	q=b;
	while(p!=NULL || q!=NULL){
		if(p==NULL){
			t->next=q;
			q=q->next;
			t=t->next;
			t->next=NULL;
		}
		else if(q==NULL){
			t->next=p;
			p=p->next;
			t=t->next;
			t->next=NULL;	
		}
		else if(p->val<=q->val){
			t->next=p;
			p=p->next;
			t=t->next;
			t->next=NULL;	
		}
		else{
			t->next=q;
			q=q->next;
			t=t->next;
			t->next=NULL;	
		}
	}
	return ans;
}

ListNode* sortList(ListNode* A) {
	if(A==NULL || A->next==NULL){
		return A;
	}
	else if(A->next->next==NULL){
		if(A->val<=A->next->val){
			return A;
		}
		else{
			ListNode *temp;
			temp=A->next;
			temp->next=A;
			A->next=NULL;
			A=temp;
			return A;
		}
	}
	ListNode *slow, *fast;
	slow=A;
	fast=A->next;
	while(fast->next!=NULL){
		slow=slow->next;
		fast=fast->next;
		if(fast->next==NULL){
			break;
		}
		fast=fast->next;
	}
	ListNode *left=A,*right=slow->next;
	slow->next=NULL;
	left=sortList(left);
	right=sortList(right);
	left=sorted_merge(left,right);
	A=left;
	return A;
}

int main(){
	ListNode *A,*p;
	A=new ListNode(3);
	p=A;
	p->next=new ListNode(2);
	p=p->next;

	p->next=new ListNode(1);
	p=p->next;

	p->next=new ListNode(5);
	p=p->next;

	p->next=new ListNode(4);
	p=p->next;

	print_list(A);
	A=sortList(A);
	print_list(A);
	return 0;
}
