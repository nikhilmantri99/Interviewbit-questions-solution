// Step 1: First of all, calculate no. of consecutive 1’s in every column.
//  An auxiliary array hist[][] is used to store the counts of consecutive 1’s.
//   So for the above first example, contents of hist[R][C] would be

//     0 1 0 1 0
//     0 2 0 2 1
//     1 3 0 3 0

// Time complexity of this step is O(R*C)

// Step 2: Sort the columns in non-increasing fashion. After sorting step the matrix hist[][] would be

//     1 1 0 0 0
//     2 2 1 0 0
//     3 3 1 0 0

// This step can be done in O(R * (R + C)). Since we know that the values are in range from 0 to R, 
// we can use counting sort for every row.
// The sorting is actually the swapping of columns. If we look at the 3rd row under step 2:
// 3 3 1 0 0
// The sorted row corresponds to swapping the columns so that the column with the highest possible rectangle 
// is placed first, after that comes the column that allows the second highest rectangle and so on. 
// So, in the example there are 2 columns that can form a rectangle of height 3. That makes an area of 3*2=6. 
// If we try to make the rectangle wider the height drops to 1, because there are no columns left that allow
//  a higher rectangle on the 3rd row.

// Step 3: Traverse each row of hist[][] and check for the max area. 
// Since every row is sorted by count of 1’s,
// current area can be calculated by multiplying 
// column number with value in hist[i][j]. This step also takes O(R * C) time.

// Below is the implementation based of above idea.

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int solve(vector<vector<int> > &A) {
	int n_rows=A.size();
	int n_cols=A[0].size();
	int i,j,k;
	int maxval=INT_MIN;
	vector <int> aux_vect(n_cols,0);
	for(i=0;i<n_rows;i++){
		for(j=0;j<n_cols;j++){
			if(A[i][j]==1){
				aux_vect[j]=aux_vect[j]+A[i][j];
			}
			else{
				aux_vect[j]=0;
			}
		}
		cout<<"aux_vect: "<<endl;
		print_vector(aux_vect);
		vector <int> counts(i+2,0);
		cout<<"counts: "<<endl;
		for(j=0;j<aux_vect.size();j++){
			counts[aux_vect[j]]=counts[aux_vect[j]]+1;
		}
		print_vector(counts);
		for(j=0;j<counts.size();j++){
			maxval=max(maxval,j*counts[j]);
		}
	}
	return maxval;
}

int main(){
	vector <vector<int>> A={{0,0,0,0},{1,1,1,1},{1,0,1,0},{0,1,0,1}};
	cout<<solve(A)<<endl;
	return 0;
}
