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

ListNode* reorderList(ListNode* A) {
	if(A==NULL){
		return A;
	}
	if(A->next==NULL){
		return A;
	}
	if(A->next->next==NULL){
		return A;
	}
	long int n=return_count(A);
	long int count=0;
	ListNode *rev_A_mid=NULL;
	ListNode *p=A,*q;
	while(count<=(n-1)/2){
		if(count==(n-1)/2){
			q=p;
		}
		count++;
		p=p->next;
	}
	q->next=NULL;
	//cout<<p->val<<endl;
	rev_A_mid=p;
	p=p->next;
	rev_A_mid->next=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=rev_A_mid;
		rev_A_mid=q;
	}
	//printLinkedList(A);
	//printLinkedList(rev_A_mid);
	p=A;
	while(rev_A_mid!=NULL){
		q=rev_A_mid;
		rev_A_mid=rev_A_mid->next;
		q->next=p->next;
		p->next=q;
		p=q->next;
	}
	//printLinkedList(A);
	return A;
}

int main(){
	ListNode *head=NULL, *p=NULL, *q=NULL;
	head=create(1);
	p=head;
	p->next=create(2);
	p=p->next;
	p->next=create(3);
	p=p->next;
	p->next=create(4);
	p=p->next;
	p->next=create(5);
	p=p->next;
	p->next=create(6);
	p=p->next;
	p->next=create(7);
	p=p->next;
	printLinkedList(head);
	head=reorderList(head);
	printLinkedList(head);
	return 0;
}