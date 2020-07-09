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

ListNode* partition(ListNode* A, int B) {
	ListNode *less=NULL,*l, *more=NULL,*m, *p, *prev_p;
	p=A;
	if(A==NULL){
		return A;
	}
	if(A->next==NULL){
		return A;
	}
	cout<<"here"<<endl;
	while(p!=NULL){
		cout<<p->val<<endl;
		prev_p=p;
		p=p->next;
		cout<<"assigned"<<endl;
		prev_p->next=NULL;
		if((prev_p->val)<B){
			if(less==NULL){
				less=prev_p;
				l=less;
			}
			else{
				l->next=prev_p;
				l=l->next;
			}
		}
		else{
			if(more==NULL){
				more=prev_p;
				m=more;
			}
			else{
				m->next=prev_p;
				m=m->next;
			}
		}
	}
	cout<<"outa here"<<endl;
	if(less==NULL){
		return more;
	}
	if(more==NULL){
		return less;
	}
	l->next=more;
	return less;
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
	printLinkedList(head);

	int B=5;
	head=partition(head,B);
	printLinkedList(head);
	return 0;
}