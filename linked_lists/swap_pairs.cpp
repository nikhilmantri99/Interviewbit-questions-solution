#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef struct ListNode{
 	int val;
 	struct ListNode *next;
}ListNode;

void printLinkedList(ListNode *head){
	ListNode *p;
	p=head;
	while(p!=NULL){
		cout<<(p->val)<<" ";
		p=(p->next);
	}
	cout<<endl;
	return;
}

ListNode * create(int temp){
	ListNode *p=new ListNode;
	p->val=temp;
	p->next=NULL;
	return p;
}

ListNode* swapPairs(ListNode* A){
	ListNode *p,*q, *t,*pre_p;
	p=A;
	if(p!=NULL){
		if(p->next!=NULL){
			q=p->next;
			p->next=p->next->next;
			q->next=p;
			A=q;
		}
		else{
			return A;
		}
	}
	else{
		return A;
	}
	printLinkedList(A);
	p=A->next->next;
	pre_p=A->next;
	//printLinkedList(p);
	while(p!=NULL ){
		if(p->next==NULL){
			break;
		}
		q=p;
		t=p->next;
		q->next=q->next->next;
		t->next=q;
		pre_p->next=t;
		p=t;
		printLinkedList(p);
		pre_p=p->next;
		p=p->next->next;
	}
	printLinkedList(A);
	return A;    
}

int main(){
	ListNode *head;
	int i,j,k;
	ListNode *q;
	head=create(1);
	q=head;
	for(i=2;i<=6;i++){
		q->next=create(i);
		q=q->next;
	}
	printLinkedList(head);
	head=swapPairs(head);
	return 0;
}