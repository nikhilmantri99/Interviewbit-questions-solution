#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

//Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
// Approach: The array elements of the given array lies from 0 to n-1. Now an array 
// element is needed that can store two different values at the same time. To achieve this 
// increment every element at ith index is incremented by (arr[arr[i]] % n)*n.After the 
// increment operation of first step, every element holds both old values and new values. Old
// value can be obtained by arr[i]%n and a new value can be obtained by arr[i]/n.
// How this can be achieved?
// Let’s assume an element is a and another element is b, both the elements are less than n. 
//So if an element a is incremented by b*n.
// So the element becomes a + b*n so when a + b*n is divided by n then the value is b and a + b*n % n is a.
void print_vec1(vector<int> &t){
    for(int i=0;i<t.size();i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
}

void arrange(vector<int> &A) {
   int i,n=A.size();
   for(i=0;i<A.size();i++){
       A[i]=A[i]+(A[A[i]]%n)*n;
   }
   for(i=0;i<A.size();i++){
       A[i]=A[i]/n;
   }
}

int main(){
    vector <int> A={4,0,2,1,3};
    arrange(A);
    print_vec1(A);
    return 0;
}
