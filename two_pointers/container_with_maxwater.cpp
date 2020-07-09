#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Approach 1 (in direction of O(n)) :
// Will the area be maximum if you take j-i to be maximum.
//If not, then can you reduce the problem to simpler set?
//What we do is we place our two pointers at the array extremes.
//Then calculate area.Update maxarea.
//Now whichever sidepole was smaller in height, we move in the corresponding direction from
//there.

int Solution::maxArea(vector<int> &A) {
    int i,j,k;
    i=0;j=A.size()-1;
    int maxarea=abs(j-i)*min(A[i],A[j]);
    while(i<=j){
        int area=abs(j-i)*min(A[i],A[j]);
        maxarea=max(maxarea,area);
        if(min(A[i],A[j])==A[i]){
            i++;
        }
        else{
            j--;
        }
    }
    return maxarea;
}
