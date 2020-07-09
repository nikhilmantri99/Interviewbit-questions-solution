#include <bits/stdc++.h>
using namespace std;

void print_vec(vector <int> &A, int left, int right){
	for(int i=left;i<=right;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

void sorted_merge(vector <int> &A,int left, int mid, int right){
	int i,j,k;
	vector <int> ans;
	i=left;
	j=mid;
	while(i<mid || j<=right){
		if(i>=mid || A[i]>A[j]){
			ans.push_back(A[j]);
			j++;
		}
		else if(j>right || A[i]<=A[j]){
			ans.push_back(A[i]);
			i++;
		}
	}
	for(i=0;i<ans.size();i++){
		A[left+i]=ans[i];
	}
	return;
}

void merge_sort(vector <int> &A, int left, int right){
	if(left==right || left+1 ==right || left>right){
		return ;
	}
	int mid=left+(right-left)/2;
	merge_sort(A,left,mid-1);
	merge_sort(A,mid,right);
	sorted_merge(A,left,mid,right);
	return ;
}

int main(){
	vector <int> A={2,7,1,1,8,12,2,6,7,19};
	print_vec(A,0,A.size()-1);
	merge_sort(A,0,A.size()-1);
	print_vec(A,0,A.size()-1);
	return 0;
}