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

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *major,*minor,*q,*prev_major;
    if(A==NULL){
    	return B;
    }
    if(B==NULL){
    	return A;
    }
    //ensure A's first element is smaller
    if(A->val>B->val){
    	ListNode *temp;
    	temp=A;
    	A=B;
    	B=temp;
    }
    cout<<"A:";
    printLinkedList(A);
    cout<<"B:";
    printLinkedList(B);
    major=A,minor=B;
    // q=minor;
    // minor=minor->next;
    // q->next=major->next;
    // major->next=q;
    // major=major->next;
    cout<<major->val<<" "<<minor->val<<endl;
    cout<<"stata of A:"<<endl;
    while(major!=NULL||minor!=NULL){
    	printLinkedList(A);
    	if(major==NULL){
    		prev_major->next=minor;
    		printLinkedList(A);
    		break;
    	}
    	else if(minor==NULL){
    		printLinkedList(A);
    		break;
    	}
    	if(major->val<=minor->val){
    		prev_major=major;
    		major=major->next;
    	}
    	else{
    		q=minor;
    		minor=minor->next;
    		q->next=major;
    		prev_major->next=q;
    		prev_major=prev_major->next;
    	}
    }
    cout<<"ultimate return: ";
    printLinkedList(A);
    return A;
}

int main(){
	ListNode *A, *B;
	A=create(5);
	A->next=create(8);
	A->next->next=create(20);

	B=create(4);
	B->next=create(11);
	B->next->next=create(15);

	cout<<"A: ";
	printLinkedList(A);
	cout<<"B: ";
	printLinkedList(B);
	ListNode *Merged=mergeTwoLists(A,B);
	printLinkedList(Merged);
	return 0;
}