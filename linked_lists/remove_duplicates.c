#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//  Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

int main(){
	struct ListNode *head;
	head=(struct Listnode *)malloc(sizeof(struct Listnode));
	head->val=1;
	head->next=(struct Listnode *)malloc(sizeof(struct Listnode));
	struct Listnode *p;
	p=head;
	p=p->next;
	p->val=2;
	p->next=(struct Listnode *)malloc(sizeof(struct Listnode));
	p->val=2;
	p->next=(struct Listnode *)malloc(sizeof(struct Listnode));
	p->val=3;
	p->next=(struct Listnode *)malloc(sizeof(struct Listnode));
	p->val=3;
	p->next=(struct Listnode *)malloc(sizeof(struct Listnode));
	p->val=4;
	p->next=NULL;
	// print_ll(head);
	return 0;
}