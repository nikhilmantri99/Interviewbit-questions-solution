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

ListNode* insertionSortList(ListNode* A) {
	if(A==NULL){
		return A;
	}
	if(A->next==NULL){
		return A;
	}
	cout<<"Sorting:"<<endl;
	ListNode *p,*q,*t,*pre_p,*pre_q,*pre_t;
	p=A->next;
	if(p->val<A->val){
		A->next=A->next->next;
		p->next=A;
		A=p;
	}
	printLinkedList(A);
	p=A->next->next;
	pre_p=A->next;
	while(p!=NULL){
		printLinkedList(A);
		q=p;
		p=p->next;
		pre_p->next=p;
		q->next=NULL;
		if(q->val<A->val){
			q->next=A;
			A=q;
		}
		else{
			t=A;
			while(t->next!=p && t->next->val<q->val){
				t=t->next;
			}
			if(t->next==p){
				q->next=p;
				pre_p=q;
				t->next=q;
			}
			else{
				q->next=t->next;
				t->next=q;
			}
			
		}
	}
	return A;
}

int main(){
	ListNode *head=NULL, *p=NULL, *q=NULL;
	head=create(6);
	p=head;
	p->next=create(4);
	p=p->next;
	p->next=create(12);
	p=p->next;
	p->next=create(37);
	p=p->next;
	p->next=create(2);
	p=p->next;
	p->next=create(0);
	p=p->next;
	p->next=create(1);
	p=p->next;
	p->next=create(9);
	p=p->next;
	p->next=create(8);
	p=p->next;
	p->next=create(33	);
	printLinkedList(head);
	head=insertionSortList(head);
	cout<<"Final Answer:"<<endl;
	printLinkedList(head);
	return 0;
}