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


ListNode* rotateRight(ListNode* A, int B) {
	int n=0;
	int i,j,k;
	i=0;
	ListNode *p,*q;
	p=A;
	printLinkedList(A);
	printLinkedList(p);
	while(p!=NULL){
		n++;
		p=p->next;
	}
	cout<<"n:"<<n<<endl;
	int target=1;
	p=A;
	B=B%n;
	if(B==0){
		return A;
	}
	while(target<n-B){
		target++;
		p=p->next;
	}
	q=p->next;
	printLinkedList(q);
	ListNode *t;
	t=p->next;
	while(t->next!=NULL){
		t=t->next;
	}
	t->next=A;
	p->next=NULL;
	printLinkedList(t->next);
	A=q;
	printLinkedList(A);
	return A;
}

int main(){
	ListNode *head;
	int i,j,k;
	ListNode *q;
	head=create(1);
	q=head;
	for(i=2;i<6;i++){
		q->next=create(i);
		q=q->next;
	}
	printLinkedList(head);
	int steps=5;
	head=rotateRight(head,steps);
	return 0;
}