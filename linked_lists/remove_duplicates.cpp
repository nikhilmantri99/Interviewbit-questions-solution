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

ListNode* deleteDuplicates(ListNode* A) {
    ListNode *current;
    current=A;
    cout<<"current: ";
    printLinkedList(current);
    // printLinkedList(A);
    if(current==NULL){
    	return A;
    }
    if(current->next==NULL){
    	return A;
    }
    while(current!=NULL){
    	printLinkedList(current);
    	if(current->next==NULL){
    		break;
    	}
    	if((*(current->next)).val==(current->val)){
    		//cout<<"here1"<<endl;
    		current->next=current->next->next;
    		continue;
    	}
    	else{
    		//cout<<"here2"<<endl;
    		current=current->next;
    	}
    }
    printLinkedList(A);
    return A;
}

int main(){
	ListNode *head;
	head=(ListNode *)malloc(sizeof(ListNode));
	ListNode *p;
	p=head;
	p->val=1;
	int i,j;
	for(i=2;i<5;i++){
		for(j=0;j<2;j++){
			p->next=new ListNode;
			p=p->next;
			p->val=i;
		}
	}
	cout<<"here"<<endl;
	p->next=NULL;
	cout<<"main: ";
	printLinkedList(head);
	head=deleteDuplicates(head);
	return 0;
}