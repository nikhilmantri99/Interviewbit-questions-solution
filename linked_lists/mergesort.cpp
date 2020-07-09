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

ListNode * merge(ListNode *A,ListNode *B){
	if(A==NULL){
		return B;
	}
	if(B==NULL){
		return A;
	}
	ListNode *p, *q,*t;
	ListNode *combined=NULL;
	p=A;
	q=B;
	while(p!=NULL || q!=NULL){
		if(q==NULL){
			t->next=p;
			p=p->next;
			t=t->next;
			t->next=NULL;
		}
		else if(p==NULL){
			t->next=q;
			q=q->next;
			t=t->next;
			t->next=NULL;
		}
		else{
			if(p->val<q->val){
				if(combined==NULL){
					combined=p;
					p=p->next;
					combined->next=NULL;
					t=combined;
				}
				else{
					t->next=p;
					p=p->next;
					t=t->next;
					t->next=NULL;
				}
			}
			else{
				if(combined==NULL){
					combined=q;
					q=q->next;
					combined->next=NULL;
					t=combined;
				}
				else{
					t->next=q;
					q=q->next;
					t=t->next;
					t->next=NULL;
				}	
			}
		}
	}
	return combined;
}

ListNode* sortList(ListNode* A) {
	ListNode *p, *q,*slow_p,*fast_p;
	if(A==NULL){
		return A;
	}
	if(A->next==NULL){
		return A;
	}
	else if(A->next->next==NULL){
		if(A->val > A->next->val){
			q=A->next;
			A->next=NULL;
			q->next=A;
			A=q;
			return A;
		}
	}
	slow_p=A;
	fast_p=A;
	while(fast_p->next!=NULL){
		if(fast_p->next->next==NULL){
			fast_p=fast_p->next;
			break;
		}
		else{
			slow_p=slow_p->next;
			fast_p=fast_p->next->next;
		}
	}
	ListNode *LHS, *RHS;
	LHS=A;
	RHS=slow_p->next;
	slow_p->next=NULL;
	LHS=sortList(LHS);
	RHS=sortList(RHS);
	A=merge(LHS,RHS);
	return A;
}


int main(){
	ListNode *A=NULL,*B=NULL,*p=NULL,*q=NULL;
	A=create(5);
	p=A;
	p->next=create(66);
	p=p->next;
	p->next=create(68);
	p=p->next;
	p->next=create(42);
	p=p->next;
	p->next=create(73);
	p=p->next;
	p->next=create(25);
	p=p->next;
	p->next=create(84);
	printLinkedList(A);
	cout<<"Sorted:"<<endl;
	A=sortList(A);
	printLinkedList(A);
	return 0;
}