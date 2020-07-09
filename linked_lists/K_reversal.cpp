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


ListNode* reverseBetween(ListNode* A, int B, int C) {
    int m=0, n;
    ListNode *p=NULL, *q=NULL, *reversed=NULL, *pre_p=NULL;
    if(B==1){
        p=A;
        while(m<C){
            m++;
            q=p;
            p=p->next;
            q->next=reversed;
            reversed=q;
        }
        A->next=p;
        return reversed;
    }

    p=A;
    pre_p=p;
    p=p->next;
    m=2;
    while(m<B){
        p=p->next;
        pre_p=pre_p->next;
        m++;
    }
    pre_p->next=reverseBetween(p,1,C-B+1);
    return A;
}
 
ListNode* reverseList(ListNode* A, int B) {
    if(A==NULL) return NULL;
    if(B==1) return A;
    A=reverseBetween(A,1,B);
    printLinkedList(A);
    ListNode *p=A;
    int i=1;
    while(i<B){
        i++;
        p=p->next;
        if(p==NULL) return NULL;
    }
    p->next=reverseList(p->next,B);
    return A;
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
    p=p->next;
    p->next=create(7);
    p=p->next;
    p->next=create(8);
    p=p->next;
    p->next=create(9);
    printLinkedList(head);
    int B;
    cin>>B;
    head=reverseList(head,B);
    printLinkedList(head);
    return 0;
}