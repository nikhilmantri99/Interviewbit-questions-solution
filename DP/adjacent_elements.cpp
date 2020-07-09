#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void pprint(vector<vector<int>> &x){
	for(int i=0;i<x.size();i++){
		print_vector(x[i]);
	}
	cout<<endl;
}

int maxi(int a,int b,int c){
	return max(max(a,b),c);
}

// This problem is an extension of Maximum sum such that no two elements are adjacent. 
//Only thing to be changed is to take maximum element of both row of a particular column.
// We traverse column by column and maintain maximum sum considering two cases.
// 1) An element of current column is included. In this case we take maximum of two elements in current column.
// 2) An element of current column is excluded (or not included)

int adjacent(vector<vector<int> > &A) {
   // Sum including maximum element of first column 
    int n=A[0].size();
    int incl = max(A[0][0], A[1][0]); 
  
    // Not including first column's element 
    int excl = 0, excl_new; 
  
    // Traverse for further elements 
    for (int i = 1; i<n; i++ ) 
    { 
        // Update max_sum on including or excluding 
        // of previous column 
        excl_new = max(excl, incl); 
  
        // Include current column. Add maximum element 
        // from both row of current column 
        incl = excl + max(A[0][i], A[1][i]); 
  
        // If current column doesn't to be included 
        excl = excl_new; 
    } 
  
    // Return maximum of excl and incl 
    // As that will be the maximum sum 
    return max(excl, incl); 
}

int main(){
	vector<vector<int>>A={{16, 5, 54, 55, 36, 82, 61, 77, 66, 61},{31, 30, 36, 70, 9, 37, 1, 11, 68, 14}};
	cout<<adjacent(A)<<endl;
	return 0;
}
