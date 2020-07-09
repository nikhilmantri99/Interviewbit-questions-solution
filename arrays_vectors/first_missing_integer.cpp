// Question:Given an unsorted integer array, find the first missing positive integer.

#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

// Following is the two step algorithm.
// 1) Segregate positive numbers from others i.e., move all non-positive numbers to left side. In the following code, segregate() function does this part.
// 2) Now we can ignore non-positive elements and consider only the part of array which contains all positive elements. 
//We traverse the array containing all positive numbers and to mark presence of an element x, 
// //we change the sign of value at index x to negative. We traverse the array again and print the first index which has positive value. 
// In the following code, findMissingPositive() function does this part. 
// Note that in findMissingPositive, we have subtracted 1 from the values as indexes start from 0 in C.

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int segregate(vector<int> &A){
	int i=0;
	for(int j=0;j<A.size();j++){
		if(A[j]>0 && A[j]<=A.size()){
			swap(&A[j],&A[i]);
			i++;
		}
	}
	return i;
}

void print_array(vector <int> &A){
	cout<<"printing:"<<endl;
	int i=0;
	for(i=0;i<A.size();i++){
		cout<<" "<<A[i];
	}
	cout<<endl;
}

int firstMissingPositive(vector<int> &A) {
	int i,j,k;
	int n=segregate(A);
	//cout <<"after segregation:";
	//print_array(A);
	if(n==0){
		return 1;
	}
	for(i=0;i<n;i++){
		A[abs(A[i])-1]=(-1)*abs(A[abs(A[i])-1]);
	}
	for(i=0;i<n;i++){
		if(A[i]>0){
			return i+1;
		}
	}
	return n+1;

}

int main(){
	int n;
	vector <int> A;
	cin>>n;
	int i,temp;
	for(i=0;i<n;i++){
		cin>>temp;
		A.push_back(temp);
	}
	cout<<"Ans: "<<firstMissingPositive(A)<<endl;
	return 0;
}