#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * create(int temp){
	ListNode *p=new ListNode(temp);
	return p;
}

void printLinkedList(ListNode *head){
	ListNode *p;
	p=head;
	int count=0;
	while(p!=NULL){
		count++;
		if(count>20){
			cout<<endl;
			return;
		}
		cout<<(p->val)<<" ";
		p=(p->next);
	}
	cout<<endl;
	return;
}

long int return_count(ListNode *head){
	long int n=0;
	ListNode *p;
	p=head;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	return n;
}

int lPalin(ListNode* A) {
	if(A==NULL) return 1;
	if(A->next==NULL) return 1;
	long int n=return_count(A),count=0;
	ListNode *LHS, *RHS,*p,*q;
	count++;
	LHS=A;
	A=A->next;
	LHS->next=NULL;
	while(count<n/2){
		count++;
		p=A;
		A=A->next;
		p->next=LHS;
		LHS=p;
	}
	cout<<"LHS: "<<endl;
	printLinkedList(LHS);
	if(n%2==1){
		RHS=A->next;
	}
	else{
		RHS=A;
	}
	cout<<"RHS: "<<endl;
	printLinkedList(RHS);
	p=LHS;
	q=RHS;
	while(p!=NULL){
		if(p->val!=q->val){
			return 0;
		}
		p=p->next;
		q=q->next;
	}
	return 1;
}

int main(){
	ListNode *head=NULL, *p=NULL, *q=NULL;
	head=create(4);
	p=head;
	p->next=create(3);
	// p=p->next;
	// p->next=create(3);
	// p=p->next;
	// p->next=create(2);
	// p=p->next;
	// p->next=create(3);
	// p=p->next;
	// p->next=create(4);
	// p=p->next;
	printLinkedList(head);
	cout<<lPalin(head)<<endl;
	return 0;
}
