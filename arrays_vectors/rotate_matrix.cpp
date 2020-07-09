#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_vec(vector <int> &x){
	for (int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void print_grid(vector <vector <int>> &A){
	for(int i=0;i<A.size();i++){
		print_vec(A[i]);
	}
	cout<<endl;
}

int send_i_limit(int n){
	if(n%2==0){
		return (n-1)/2;
	}
	else{
		return ((n-1)/2)-1;
	}
}

int send_j_limit(int n){
	return (n-1)/2;
}

vector <int> rotated_coordinates(int ya, int xa, int n){
	int xf=-ya+(n-1);
	int yf=xa;
	vector <int> ans(2);
	ans[0]=yf;//i
	ans[1]=xf;//j
	return ans;
}



void rotate(vector<vector<int>> &A){
	int n=A.size();
	int i,j,i_upper=send_i_limit(n),j_upper=send_j_limit(n);
	if(n==1){
		return;		
	}
	for(i=0;i<=i_upper;i++){
		for(j=0;j<=j_upper;j++){
			vector <int> ans;
			ans=rotated_coordinates(i,j,n);
			int temp=A[ans[0]][ans[1]];
			A[ans[0]][ans[1]]=A[i][j];

			vector <int> ans1;
			ans1=rotated_coordinates(ans[0],ans[1],n);
			int temp1=A[ans1[0]][ans1[1]];
			A[ans1[0]][ans1[1]]=temp;
			
			vector <int> ans2;
			ans2=rotated_coordinates(ans1[0],ans1[1],n);
			int temp2=A[ans2[0]][ans2[1]];
			A[ans2[0]][ans2[1]]=temp1;

			A[i][j]=temp2;
		}
	}
	print_grid(A);
	return ;
}

int main(){
	vector <vector <int>> A={{1,2,3},{4,5,6},{7,8,9}};
	print_grid(A);
	rotate(A);
	return 0;
}

