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

ListNode* removeNthFromEnd(ListNode* A, int B) {
	int n=0;
	if (B==0){
		return A;
	}
	ListNode *p;
	p=A;
	while(p!=NULL){
		n++;
		p=p->next;
	}
	if(n==0){
		return A;
	}
	cout<<"num of elements:"<<n<<endl;
	if(B>=n){
		return A->next;
	}
	int target=1;
	p=A;
	while(target<n-B){
		target++;
		p=p->next;
	}
	p->next=p->next->next;
	printLinkedList(A);
	return A;
}

int main(){
	ListNode *head;
	ListNode *p;
	head=new ListNode;
	head->val=1;
	head->next=new ListNode;
	p=head;
	for (int i=2;i<6;i++){
		p=p->next;
		p->val=i;
		p->next=new ListNode;
	}
	p->next=NULL;
	printLinkedList(head);
	int B=6;
	head=removeNthFromEnd(head,B);
	printLinkedList(head);
	return 0;
}
