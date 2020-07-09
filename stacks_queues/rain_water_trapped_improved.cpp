#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Given n non-negative integers representing an elevation map where the width of each bar is 1,
//compute how much water it is able to trap after raining.


// Take a close look at any particular bin. How high can this hold water? 
//If you can compute the answer of the above question for every bin you are done.
// Every bin will store water which will depend on some prefix and suffix quantity. 
//Can you figure it out now?

//Yes, the height of water above a bin will depend on the maximum bin height to its left, and right. So we maintain
//two arrays tallest left and tallest right representing tallest bin to left and right. find minimum of the two heights for
//every i. Till that height water can be stored on top of bin. draw a few elevation maps and you will notice this algo working.  

int trap(const vector<int> &A) {
    if(A.size()<=2){
        return 0;
    }
    int n=A.size();
    vector tallest_left(A.size(),0);
    vector tallest_right(A.size(),0);
    tallest_left[0]=A[0];
    tallest_right[n-1]=A[n-1];
    int i,j,k;
    int ans=0;
    for(i=1;i<n;i++){
        tallest_left[i]=max(tallest_left[i-1],A[i]);
    }
    for(i=n-2;i>=0;i--){
        tallest_right[i]=max(tallest_right[i+1],A[i]);
    }
    for(i=0;i<A.size();i++){
        if(i==0 || i==A.size()-1){
            continue;
        }
        int h=min(tallest_left[i],tallest_right[i]);
        if(h<=A[i]){
            continue;
        }
        ans+=h-A[i];
    }
    return ans;
}

int main(){
	vector <int> A={2, 0, 2};
	cout<<trap(A)<<endl;
	return 0;
}