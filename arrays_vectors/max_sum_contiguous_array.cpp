#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int Solution::maxSubArray(const vector<int> &A) {
    int i,j,k;
    int current_max=A[0],max_so_far=A[0];
    for(i=1;i<A.size();i++){
        if (current_max+A[i]>A[i]){
            current_max+=A[i];
        }
        else{
            current_max=A[i];
        }
        if (current_max>max_so_far){
            max_so_far=current_max;
        }
        
    }
    return max_so_far;
}