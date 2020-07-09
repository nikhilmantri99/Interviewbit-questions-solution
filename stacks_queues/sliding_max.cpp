#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Question: Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
// Answer:We create a Deque, Qi of capacity k, that stores only useful elements of current window of k elements. An element is useful if it is in current window and is greater than all other elements on left side of it in current window. We process all array elements one by one and maintain Qi to contain useful elements of current window and these useful elements are maintained in sorted order. The element at front of the Qi is the largest and element at rear of Qi is the smallest of current window. Thanks to Aashish for suggesting this method.
// Below image is a dry run of the above approach:

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}



vector<int> slidingMaximum(const vector<int> &A, int B) {
	deque <int> q;//to store indexes of maximum till current;
	int i;
	for(i=0;i<B && i<A.size();i++){
		if(q.empty()){
			q.push_back(i);
		}
		else{
			while(q.empty()==false){
				if(A[q.back()]<A[i]){
					q.pop_back();
				}
				else{
					break;
				}
			}
			q.push_back(i);
		}
	}
	vector <int> ans;
	ans.push_back(A[q.front()]);
	for(;i<A.size();i++){
		while(q.empty()==false){
			if(q.front()<i-B+1){
				q.pop_front();
			}
			else{
				break;
			}
		}
		while(q.empty()==false){
			if(A[q.back()]<A[i]){
				q.pop_back();
			}
			else{
				break;
			}
		}
		q.push_back(i);
		ans.push_back(A[q.front()]);
	}
	return ans;
}

int main(){
	vector <int> A={648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368};
	int B=9;
	vector <int> ans=slidingMaximum(A,B);
	print_vector(ans);
	return 0;
}