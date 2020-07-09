#include <bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
	int n_rows=A.size();
	int n_cols=A[0].size();
	int start=0,end=n_rows-1,row_found=-1;
	while(start<=end){
		int mid=(start+end)/2;
		//cout<<"first while: "<<mid<<endl;
		if(A[mid][0]<=B && A[mid][n_cols-1]>=B){
			row_found=mid;
			break;
		}
		else if(A[mid][0]>B){
			end=mid-1;
		}
		else if(A[mid][n_cols-1]<B){
			start=mid+1;
		}
	}
	if(row_found==-1){
		return 0;
	}
	start=0,end=n_cols-1;   
	while(start<=end){
		int mid=(start+end)/2;
		//cout<<"second while: "<<mid<<endl;
		if(A[row_found][mid]==B){
			return 1;
		}
		else if(A[row_found][mid]>B){
			end=mid-1;
		}
		else if(A[row_found][mid]<B){
			start=mid+1;
		}
	}
	return 0;
}

int main(){
	int N_rows,N_cols;
	cin>>N_rows>>N_cols;
	int i,j;
	vector<vector<int>> A;
	int temp;
	for(i=0;i<N_rows;i++){
		vector <int> temp1;
		for(j=0;j<N_cols;j++){
			cin>>temp;
			temp1.push_back(temp);
		}
		A.push_back(temp1);
	}
	int val;
	cin>>val;
	cout<<searchMatrix(A,val)<<endl;
	return 0;
}