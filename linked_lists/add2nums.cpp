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
	while(p!=NULL){
		cout<<(p->val)<<" ";
		p=(p->next);
	}
	cout<<endl;
	return;
}

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
 	ListNode *ans,*p;
 	if(A==NULL){
 		return B;
 	}
 	if(B==NULL){
 		return A;
 	}
 	int sum=0,carry=0;
 	sum=A->val+B->val;
 	carry=sum/10;
 	sum=sum%10;
 	ans=create(sum);
 	//printLinkedList(ans);
 	A=A->next;
 	B=B->next;
 	p=ans;
 	while(A!=NULL || B!=NULL){
 		//printLinkedList(ans);
 		if(A==NULL){
 			sum=B->val+carry;
 			carry=sum/10;
 			sum=sum%10;
 			p->next=create(sum);
 			p=p->next;
 			B=B->next;

 		}
 		else if(B==NULL){
 			sum=A->val+carry;
 			carry=sum/10;
 			sum=sum%10;
 			p->next=create(sum);
 			p=p->next;
 			A=A->next;
 		}
 		else{
 			sum=A->val+B->val+carry;
 			carry=sum/10;
 			sum=sum%10;
 			p->next=create(sum);
 			p=p->next;
 			A=A->next;
 			B=B->next;
 		}
 	}
 	if(carry!=0){
 		p->next=create(carry);
 	}
 	return ans;
}

int main(){
	ListNode *A,*B,*p,*q;
	A=create(2);
	p=A;
	p->next=create(4);

	B=create(5);
	p=B;
	p->next=create(6);
	p=p->next;
	p->next=create(4);

	cout<<"A: ";
	printLinkedList(A);
	cout<<"B: ";
	printLinkedList(B);
	ListNode *head= addTwoNumbers(A,B);
	printLinkedList(head);
	return 0;
}