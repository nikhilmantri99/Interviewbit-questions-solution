#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int box_number(int row, int col){
	if(row>=0 && row<=2){
		if(col>=0 && col<=2){
			return 0;
		}
		if(col>=3 && col<=5){
			return 1;
		}
		if(col>=6 && col<=8){
			return 2;
		}
	}
	if(row>=3 && row<=5){
		if(col>=0 && col<=2){
			return 3;
		}
		if(col>=3 && col<=5){
			return 4;
		}
		if(col>=6 && col<=8){

		}	return 5;
	}
	if(row>=6 && row<=8){
		if(col>=0 && col<=2){
			return 6;
		}
		if(col>=3 && col<=5){
			return 7;
		}
		if(col>=6 && col<=8){
			return 8;
		}		
	}
}


int Solution::isValidSudoku(const vector<string> &A) {
	vector <vector<bool>> horizontals;
	vector <vector<bool>> verticals;
	vector <vector<bool>> boxes;
	vector <bool> temp;
	for(int i=0;i<10;i++){
		temp.push_back(true);
	}
	for(int i=0;i<9;i++){
		horizontals.push_back(temp);
		verticals.push_back(temp);
		boxes.push_back(temp);
	}
	for(int i=0;i<9;i++){//row
		for(int j=0;j<9;j++){//col
			if((int)(A[i][j]-'0')>9 || (int)(A[i][j]-'0')<1){
				continue;
			}
			else if(horizontals[i][(int)(A[i][j]-'0')]==true && verticals[j][(int)(A[i][j]-'0')]==true && boxes[box_number(i,j)][(int)(A[i][j]-'0')]==true){
				horizontals[i][(int)(A[i][j]-'0')]=false;
				verticals[j][(int)(A[i][j]-'0')]=false;
				boxes[box_number(i,j)][(int)(A[i][j]-'0')]=false;
			}
			else{
				return 0;
			}
		}
	}
	return 1;
}
//write main function. too tired lol
