// We are going to solve this using dynamic approach because when a new column 
//is added to the board, the ways in which colors are going to be filled depends 
//just upon the color pattern in the current column. We can only have a combination of two colors 
//and three colors in a column. All possible new columns that can be generated is given in the image.
// Please consider A, B, C and D as 4 colors.
// Image Containing Color Combination Generation

// All possible color combinations that can be generated from current column.
//https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/
// From now, we will refer 3 colors combination for a Nth column of the 3*N board as W(n) and two colors as Y(n).
// We can see that each W can generate 5Y and 11W, and each Y can generate 7Y and 10W. We get two equation from here
// We have two equations now,
	//3 color- W(n) 
	//2 color Y(n). 
//Base case: W(1)= 24, Y(1)=12
// W(n+1) = 10*Y(n)+11*W(n);
// Y(n+1) = 7*Y(n)+5*W(n);
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solve(int A){
	int M=pow(10,9)+7;
	long long int Y=12;
	long long int W=24;
	for(int i=2;i<=A;i++){
		long long int W_=((10*(Y%M))%M + (11*(W%M))%M)%M;
		long long int Y_=((7*(Y%M))%M+(5*(W%M))%M)%M;
		W=W_;
		Y=Y_;
	}
	return (W+Y)%M;
}

int main(){
	int A;
	cin>>A;
	cout<<solve(A)<<endl;
	return 0;
}
