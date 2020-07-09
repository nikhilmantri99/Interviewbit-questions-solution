#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void print_vec(vector <vector<int>> &A){
	int i,j;
	for(i=0;i<A.size();i++){
		for(j=0;j<A[i].size();j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

int binary_search(vector <int> &A, int left, int right, int val){
	if(left>=A.size() || right>=A.size()){
		return -1;
	}
	if(left>right){
		return -1;
	}
	int mid=(left+right)/2;
	if(A[mid]==val){
		return mid;
	}
	if(val<A[mid]){
		return binary_search(A,left,mid-1,val);
	}
	else{
		return binary_search(A,mid+1,right,val);
	}
}

vector <vector<int>> threeSum(vector<int> &A) {
	int i,j,k;
	vector <vector<int>> result;
	vector <int> temp;
	sort(A.begin(),A.end());
	i=0;
	while(A[i]<=0 && i<A.size()){
		if(i>0 && A[i]==A[i-1]){
			i++;
			continue;
		}
		else{
			j=i+1;
			while(j<A.size()){
				if(j>i+1 && A[j]==A[j-1]){
					j++;
					continue;
				}
				int apb=-1*A[i];
				int a=apb-A[j];
				if(binary_search(A,j+1,A.size()-1,a)>=0){
					temp.clear();
					temp.push_back(A[i]);
					temp.push_back(A[j]);
					temp.push_back(a);
					result.push_back(temp);
				}
				j++;
			}
			i++;
		}
	}
	print_vec(result);
	return result;
}


int main(){
	vector <int> A={-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3 };
	sort(A.begin(),A.end());
	print_vector(A);
	vector <vector <int>> C=threeSum(A);
	return 0;
}
