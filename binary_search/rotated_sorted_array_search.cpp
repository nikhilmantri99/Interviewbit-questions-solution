#include <bits/stdc++.h>
using namespace std;

// We can search an element in one pass of Binary Search. The idea is to search

// 1) Find middle point mid = (l + h)/2
// 2) If key is present at middle point, return mid.
// 3) Else If arr[l..mid] is sorted
//     a) If key to be searched lies in range from arr[l]
//       to arr[mid], recur for arr[l..mid].
//     b) Else recur for arr[mid+1..h]
// 4) Else (arr[mid+1..h] must be sorted)
//     a) If key to be searched lies in range from arr[mid+1]
//       to arr[h], recur for arr[mid+1..h].
//     b) Else recur for arr[l..mid] 


int search(const vector<int> &A, int B) {
    int left=0,right=A.size()-1,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(A[mid]==B){
            return mid;
        }
        else if(A[left]<=A[mid]){
            if(A[left]<=B && B<A[mid]){
                right=mid-1;
                continue;
            }
            else{
                left=mid+1;
                continue;
            }
        }
        else if(A[mid]<=A[right]){
            if(A[mid]<B && B<=A[right]){
                left=mid+1;
                continue;
            }
            else{
                right=mid-1;
                continue;
            }
        }
    }
    return -1;
}
