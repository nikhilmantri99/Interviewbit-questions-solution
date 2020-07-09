#include <bits/stdc++.h>
#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


// Approach using label to its address mapping hashmap;
RandomListNode* copyRandomList(RandomListNode* A) {
	//unordered_map <int,RandomListNode*> points_to;
	unordered_map <int, RandomListNode*> Node_and_pointer2itself;
	RandomListNode *head =new RandomListNode(A->value);
	RandomListNode *p;
	p=A->next;
	q=head;
	while(p!=NULL){
		q->next= new RandomListNode(p->label);
		p=p->next;
		q=q->next;
	}
	q=head;
	while(q!=NULL){
		Node_and_pointer2itself[q->label]=q;
		q=q->next;
	}
	q=head;
	p=A;
	while(q!=NULL){
		if(p->random==NULL){
			q->random=NULL;
		}
		else{
			q->random=Node_and_pointer2itself[p->random->value];
		}
		p=p->next;
		q=q->next;
	}
	return head;
}

// //Approach 2;
// Method 1 (Uses O(n) extra space)
// This method stores the next and arbitrary mappings (of original list) in an array first, then modifies the original Linked List (to create copy), creates a copy. And finally restores the original list.

// 1) Create all nodes in copy linked list using next pointers.
// 2) Store the node and its next pointer mappings of original linked list.
// 3) Change next pointer of all nodes in original linked list to point to the corresponding node in copy linked list.
// Following diagram shows status of both Linked Lists after above 3 steps. The red arrow shows arbit pointers and black arrow shows next pointers.

// ArbitLinked List2

// Figure 2

// 4) Change the arbit pointer of all nodes in copy linked list to point to corresponding node in original linked list.
// 5) Now construct the arbit pointer in copy linked list as below and restore the next pointer of nodes in the original linked list.

//        copy_list_node->arbit =
//                       copy_list_node->arbit->arbit->next;
//        copy_list_node = copy_list_node->next; 

// 6) Restore the next pointers in original linked list from the stored mappings(in step 2).

// Time Complexity:  O(n)
// Auxiliary Space:  O(n)
//We use the original list's next and random pointers to store our new list's node addresses
//doesnt give MLE.
//sexy question
RandomListNode* copyRandomList2(RandomListNode* A) {
	//unordered_map <int,RandomListNode*> points_to;
	//unordered_map <int, RandomListNode*> Node_and_pointer2itself;
	RandomListNode *head =new RandomListNode(A->label);
	RandomListNode *p,*q;
	p=A->next;
	q=head;
	while(p!=NULL){
		q->next= new RandomListNode(p->label);
		p=p->next;
		q=q->next;
	}
	q=head;
	p=A;
	while(p!=NULL){
		RandomListNode  *temp=p->next;
		q->random=p;
		p->next=q;
		p=temp;
		q=q->next;
	}
	q=head;
	while(q!=NULL){
	    if(q->random->random==NULL){
	        q->random=NULL;
	    }
	    else{
		    q->random=q->random->random->next;
	    }
		q=q->next;
	}
	return head;
}
