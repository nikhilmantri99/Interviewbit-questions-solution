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
	if(head==NULL){
		cout<<endl;
		return;
	}
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

ListNode* deleteDuplicates(ListNode* A) {
	if(A==NULL) return A;
	if(A->next==NULL) return A;
	if(A->next->next==NULL){
		if(A->val==A->next->val){
			return NULL;
		}
		else{
			return A;
		}
	}
	ListNode *p, *q;
	if(A->val==A->next->val){
		int temp=A->val;
		while(A!=NULL){
			if(A->val!=temp){
				break;
			}
			//cout<<"HERE"<<endl;
			A=A->next;
		}
		//printLinkedList(A);
		return deleteDuplicates(A);
	}
	//cout<<"here"<<endl;
	p=A;
	p->next=deleteDuplicates(p->next);
	return A;
}

int main(){
	ListNode *head=NULL, *p=NULL, *q=NULL;
	head=create(1);
	p=head;
	p->next=create(1);
	p=p->next;
	p->next=create(1);
	p=p->next;
	p->next=create(1);
	p=p->next;
	p->next=create(3);
	p=p->next;
	p->next=create(3);
	p=p->next;
	p->next=create(6);
	p=p->next;
	p->next=create(7);
	p=p->next;
	p->next=create(7);
	printLinkedList(head);
	head=deleteDuplicates(head);
	printLinkedList(head);
	return 0;
}

