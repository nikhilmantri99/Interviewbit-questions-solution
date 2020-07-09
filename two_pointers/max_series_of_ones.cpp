#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector <int> construct(int start, int len){
    vector <int> ans;
    for(int i=start;i<start+len;i++){
        ans.push_back(i);
    }
    return ans;
}

// Hint : Think in terms of 2 pointers.
// Would it help if you maintained the number of 0s in the current range ? When would you range become invalid ?
//We maintained the lost of indices where zeros occur. and proceeded by selecting B consecutive zeros and checking their 
//impact.

vector <int> maxone(vector<int> &A, int B) {
    vector <int> zeros;
    zeros.push_back(-1);
    int start,len=INT_MIN;
    int i,j,k;
    for(i=0;i<A.size();i++){
        if(A[i]==0){
            zeros.push_back(i);
        }
    }
    zeros.push_back(A.size());
    if(B+2>=zeros.size()){
        return construct(0,A.size());
    }
    for(i=1;i<zeros.size()-B;i++){
        int current=zeros[i+B]-zeros[i-1]-1;
        if(current>len){
            start=zeros[i-1]+1;
            len=current;
        }
    }
    return construct(start,len);
}
