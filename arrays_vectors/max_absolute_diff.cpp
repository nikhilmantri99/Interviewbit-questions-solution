#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Case 1: A[i] > A[j] and i > j
// |A[i] - A[j]| = A[i] - A[j]
// |i -j| = i - j
// hence, f(i, j) = (A[i] + i) - (A[j] + j)

// Case 2: A[i] < A[j] and i < j
// |A[i] - A[j]| = -(A[i]) + A[j]
// |i -j| = -(i) + j
// hence, f(i, j) = -(A[i] + i) + (A[j] + j)

// Case 3: A[i] > A[j] and i < j
// |A[i] - A[j]| = A[i] - A[j]
// |i -j| = -(i) + j
// hence, f(i, j) = (A[i] - i) - (A[j] - j)

// Case 4: A[i] < A[j] and i > j
// |A[i] - A[j]| = -(A[i]) + A[j]
// |i -j| = i - j
// hence, f(i, j) = -(A[i] - i) + (A[j] - j)

// Note that case 1 and 2 are equivalent and so are 
// case 3 and 4 and hence we can design our algorithm only for 
// two cases as it will cover all the possible cases.

int Solution::maxArr(vector<int> &A) {
    if(A.size()<=1){
        return 0;
    }
    int maxAiplusi=INT_MIN,minAiplusi=INT_MAX,maxAiminusi=INT_MIN,minAiminusi=INT_MAX;
    for(int i=0;i<A.size();i++){
        maxAiplusi=max(A[i]+i,maxAiplusi);
        minAiplusi=min(A[i]+i,minAiplusi);
        maxAiminusi=max(maxAiminusi,A[i]-i);
        minAiminusi=min(minAiminusi,A[i]-i);
    }
    return max(abs(maxAiplusi-minAiplusi),abs(maxAiminusi-minAiminusi));
}
