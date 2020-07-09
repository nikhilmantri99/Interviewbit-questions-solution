#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

//QUESTION:	 Find the largest continuous sequence in a array which sums to zero.
// Lets try to reduce the problem to a much simpler problem.
// Lets say we have another array sum where

//   sum[i] = Sum of all elements from A[0] to A[i]

// Note that in this array, sum of elements from A[i] to A[j] = Sum[j] - Sum[i-1]

// We need to find j and i such that sum of elements from A[i] to A[j] = 0
//  Or Sum[j] - Sum[i-1] = 0
//  Or Sum[j] = Sum[i-1]

// Now, the problem reduces to finding 2 indices i and j such that sum[i] = sum[j]
// How can you solve the above problem ?// by unordered maps


struct node{
	int lower;
	int upper;
};


vector<int> lszero(vector<int> &A) {
	vector <int> sum;// create an array such that sum[i]=sum of numbers from A[0] to A[i];
	for(int i=0;i<A.size();i++){
		if(i==0){
			sum.push_back(A[0]);
			continue;
		}
		sum.push_back(sum[i-1]+A[i]);
	}
	//We have to find i & j such that sum[i]=sum[j] and therefor our array will be from i+1 till j;
	stack <node> ans;
	unordered_map <int,int> umap;
	umap[0]=-1;
	for(int i=0;i<sum.size();i++){
		if(sum[i]==0){
			if(ans.empty()){
				node temp;
				temp.lower=umap[sum[i]]+1;
				temp.upper=i;
				ans.push(temp);
			}
			else{
				if(ans.top().upper-ans.top().lower+1<i-(umap[sum[i]]+1)+1){
					ans.pop();
					node temp;
					temp.lower=umap[sum[i]]+1;
					temp.upper=i;
					ans.push(temp);
				}
				else if(ans.top().upper-ans.top().lower+1==i-(umap[sum[i]]+1)+1){
					if(umap[sum[i]]+1<ans.top().lower){
						ans.pop();
						node temp;
						temp.lower=umap[sum[i]]+1;
						temp.upper=i;
						ans.push(temp);
					}
				}
			}
		}
		else if(umap.find(sum[i])==umap.end()){
			umap[sum[i]]=i;
		}
		else{
			if(ans.empty()){
				node temp;
				temp.lower=umap[sum[i]]+1;
				temp.upper=i;
				ans.push(temp);
			}
			else{
				if(ans.top().upper-ans.top().lower+1<i-(umap[sum[i]]+1)+1){
					ans.pop();
					node temp;
					temp.lower=umap[sum[i]]+1;
					temp.upper=i;
					ans.push(temp);
				}
				else if(ans.top().upper-ans.top().lower+1==i-(umap[sum[i]]+1)+1){
					if(umap[sum[i]]+1<ans.top().lower){
						ans.pop();
						node temp;
						temp.lower=umap[sum[i]]+1;
						temp.upper=i;
						ans.push(temp);
					}
				}
			}	
		}
	}
	vector <int> vec;
	if(ans.empty()){
		return vec;
	}
	else{
		for(int i=ans.top().lower;i<=ans.top().upper;i++){
			vec.push_back(A[i]);
		}
	}
	return vec;
}

int main(){
	vector <int> A={1 ,2 ,-2 ,4 ,-4};
	vector <int> ans=lszero(A);
	print_vector(ans);
	return 0;
}