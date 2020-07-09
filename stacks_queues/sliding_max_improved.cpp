#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Algorithm :

//     Create a deque to store k elements.
//     Run a loop and insert first k elements in the deque. While inserting the element if the element at the back of the queue is smaller than the current element remove all those elements and then insert the element.
//     Now, run a loop from k to end of the array.
//     Print the front element of the array
//     Remove the element from the front of the queue if they are out of the current window.
//     Insert the next element in the deque. While inserting the element if the element at the back of the queue is smaller than the current element remove all those elements and then insert the element.
//     Print the maximum element of the last window.

int maxval(const vector <int> &x){
	int m=INT_MIN;
	for(int i=0;i<x.size();i++){
		m=max(m,x[i]);
	}
	return m;
}

vector<int> slidingMaximum(const vector<int> &A, int B) {
    vector <int> ans;
    if(B>=A.size()){
        ans.push_back(maxval(A));
        return ans;
    }
    deque <int> dq;//stores indices of elements;
    int i,j,k;
    for(i=0;i<B;i++){
        while(!dq.empty() && A[dq.back()]<A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(A[dq.front()]);
    for(i=B;i<A.size();i++){
        //cleaning
        while(!dq.empty() && dq.back()<i-B+1){
            dq.pop_back();
        }
        while(!dq.empty() && dq.front()<i-B+1){
            dq.pop_front();
        }
        
        //insertion cleaning
        while(!dq.empty() && A[dq.back()]<A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(A[dq.front()]);
    }
    return ans;
}
