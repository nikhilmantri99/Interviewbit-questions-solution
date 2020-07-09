#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_matrix(vector<vector<int>> &A){
	int i,j;
	for(i=0;i<A.size();i++){
		for(j=0;j<A[0].size();j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void populate_col_matrix(vector<vector<int> > &A,vector <vector <int>> &matrix){
	int i,j;
	for(i=0;i<A.size();i++){
		for(j=0;j<A[0].size();j++){
			if(i==0){
				matrix[i][j]+=A[i][j];
			}
			else{
				if(A[i][j]==0){
					matrix[i][j]=0;
				}
				else{
					matrix[i][j]=matrix[i-1][j]+1;
				}
			}
		}
	}
}

void populate_row_matrix(vector<vector<int> > &A,vector <vector <int>> &matrix){
	int i,j;
	for(i=0;i<A.size();i++){
		for(j=0;j<A[0].size();j++){
			if(j==0){
				matrix[i][j]+=A[i][j];
			}
			else{
				if(A[i][j]==0){
					matrix[i][j]=0;
				}
				else{
					matrix[i][j]=matrix[i][j-1]+1;
				}
			}
		}
	}
}

int maximalRectangle(vector<vector<int> > &A) {
	vector <vector <int>> DP(A.size(),vector <int> (A[0].size(),0));
	vector <vector <int>> col1streak(A.size(),vector <int> (A[0].size(),0));
	vector <vector <int>> row1streak(A.size(),vector <int> (A[0].size(),0));
	print_matrix(A);
	populate_row_matrix(A,row1streak);
	populate_col_matrix(A,col1streak);
	print_matrix(row1streak);
	print_matrix(col1streak);

	int i,j,k;
	int maxarea=0;
	for(i=0;i<A.size();i++){
		for(j=0;j<A[0].size();j++){
			if(i==0 || j==0){
				DP[i][j]+=A[i][j];
			}
			else if(A[i][j]==0){
				DP[i][j]=0;
			}
			else{
				int x=sqrt(DP[i-1][j-1])+1;
				int y=row1streak[i][j];
				int z=col1streak[i][j];
				DP[i][j]=pow(min(min(x,y),z),2);
			}
			maxarea=max(maxarea,DP[i][j]);
		}
	}
	print_matrix(DP);
	return maxarea;
}

int main(){
	vector <vector <int>> A={{1,1,1,1},{1,1,1,1},{1,1,1,1}};
	cout<<maximalRectangle(A)<<endl;
	return 0;
}
