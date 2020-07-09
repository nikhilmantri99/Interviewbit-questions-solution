#include <bits/stdc++.h>
#include <iostream>

using namespace std;



// Try to compute longest increasing subsequence ending at ith position for all i.
// Think how can you use answers ending on 1st,2nd,3rd,….(i-1)th positions for computing answers ending on ith position.
// Hint: Expected Complexity - O(n^2)


// Optimal Substructure:
// Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.
// Then, L(i) can be recursively written as:
// L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
// L(i) = 1, if no such j exists.

int lis(const vector<int> &A) {
    vector <int> L(A.size(),1);
    int i,j;
    L[0]=1;
    for(i=1;i<A.size();i++){
        int maxlength=1;
        for(j=0;j<i;j++){
            if(A[j]<A[i]){
                if(1+L[j]>maxlength){
                    maxlength=1+L[j];
                }
            }
            L[i]=maxlength;
        }
    }
    int maxlength=0;
    for(i=0;i<L.size();i++){
        maxlength=max(maxlength,L[i]);
    }
    return maxlength;
}