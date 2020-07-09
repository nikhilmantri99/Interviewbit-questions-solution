#include <bits/stdc++.h>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 //Floyd’s loop detection algorithm. 
// 1. If a loop is found, initialize slow pointer to head, let fast pointer be at its position.
// 2. Move both slow and fast pointers one node at a time.
// // 3. The point at which they meet is the start of the loop. 
// We can conclude below from above diagram


// Distance traveled by fast pointer = 2 * (Distance traveled 
//                                          by slow pointer)

// (m + n*x + k) = 2*(m + n*y + k)

// Note that before meeting the point shown above, fast
// was moving at twice speed.

// x -->  Number of complete cyclic rounds made by 
//       fast pointer before they meet first time

// y -->  Number of complete cyclic rounds made by 
//       slow pointer before they meet first time

// From above equation, we can conclude below

//     m + k = (x-2y)*n

// Which means m+k is a multiple of n. 

// So if we start moving both pointers again 
//at same speed such that one pointer (say slow) begins from head node 
//of linked list and other pointer (say fast) begins from meeting point. 
//When slow pointer reaches beginning of loop (has made m steps), fast pointer 
//would have made also moved m steps as they are now moving same pace. 
//Since m+k is a multiple of n and fast starts from k, they would meet at 
//the beginning. Can they meet before also? No because slow pointer enters the cycle 
//first time after m steps.
 
ListNode* Solution::detectCycle(ListNode* A) {
    if(A==NULL || A->next==NULL){
        return NULL;
    }
    ListNode *slow=A,*fast=A->next;
    while(fast!=NULL){
        if(slow==fast){
            break;
        }
        slow=slow->next;
        fast=fast->next;
        if(fast==NULL){
            return NULL;
        }
        fast=fast->next;
    }
    if(fast==NULL){
        return NULL;
    }
    fast=fast->next;
    slow=A;
    while(fast!=slow){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
