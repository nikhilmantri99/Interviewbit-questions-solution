#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Floyd’s Cycle-Finding Algorithm: This is the fastest method and has been described below:

//    Traverse linked list using two pointers. 
//    Move one pointer(slow_p) by one and another pointer(fast_p) by two. 
//    If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop


// We have discussed Floyd’s loop detection algorithm. Below are steps to find first node of loop.
// 1. If a loop is found, initialize slow pointer to head, let fast pointer be at its position.
// 2. Move both slow and fast pointers one node at a time.
// 3. The point at which they meet is the start of the loop.
// How does this approach work?
// Let slow and fast meet at some point after Floyd’s Cycle finding algorithm
// We can conclude below from above diagram


// Distance traveled by fast pointer = 2 * (Distance traveled 
//                                          by slow pointer)

// (m + n*x + k) = 2*(m + n*y + k)

// Note that before meeting the point shown above, fast
// was moving at twice speed.
// n-->   number of nodes in the cyclic part
// m-->   distance of head from start node of cyclic part
// k-->   ((distance of the meeting point node)%n) from the starting point of the cyclic part
// x-->   number of cycles by slow_p
// y-->   number of cycles by fast_p

// x -->  Number of complete cyclic rounds made by 
//        fast pointer before they meet first time

// y -->  Number of complete cyclic rounds made by 
//        slow pointer before they meet first time
//From above equation, we can conclude below

//     m + k = (x-2y)*n

// Which means m+k is a multiple of n. 

// So if we start moving both pointers again at same speed such that one pointer (say slow)
//  begins from head node of linked list and other pointer (say fast) begins from meeting point.
//   When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made 
//   also moved m steps as they are now moving same pace. Since m+k is a multiple of n and fast starts 
//   from k, they would meet at the beginning. Can they meet before also? No because slow pointer enters 
//   the cycle first time after m steps.


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

ListNode* detectCycle(ListNode* A) {
	ListNode *slow_p ,*fast_p;
	slow_p=A;
	fast_p=A;
	if(A==NULL ){
		return NULL;
	}
	if( A->next==NULL){
		return NULL;
	}
	if(A->next->next==NULL){
		return NULL;
	}
	slow_p=slow_p->next;//remember slow moves 1 and fast moves 2 steps. Only then will this algo work or it will be stuck
	// in an infinite loop
	fast_p=fast_p->next->next;
	while(1){
		cout<<"Node: "<<slow_p->val<<endl;
		if(fast_p->next==NULL){
			cout<<"here1"<<endl;
			return NULL;
		}
		if(fast_p->next->next==NULL){
			cout<<"here2"<<endl;
			return NULL;
		}
		if(fast_p==slow_p){
			cout<<"here3"<<endl;
			slow_p=A;
			while(slow_p!=fast_p){
				cout<<"here4"<<endl;
				slow_p=slow_p->next;
				fast_p=fast_p->next;
			}
			cout<<"fast_p->val: "<<fast_p->val<<endl;
			return fast_p;
		}
		slow_p=slow_p->next;
		fast_p=fast_p->next->next;
	}
}

int main(){
	ListNode *q,*head,*p,*t;
	head=create(1);
	p=head;
	p->next=create(2);
	p=p->next;
	p->next=create(3);
	q=p->next;
	p=p->next;
	p->next=create(4);
	p=p->next;
	p->next=create(5);
	p=p->next;
	p->next=q;
	//printLinkedList(head);
	t=detectCycle(head);
	return 0;
}