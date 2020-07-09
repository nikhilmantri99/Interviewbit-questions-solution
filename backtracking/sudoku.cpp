#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector_bool(vector <bool> &x){
	if(x.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void print_grid_bool(vector<vector<bool>> &y){
	if(y.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<y.size();i++){
		print_vector_bool(y[i]);
	}
	cout<<endl;
}


void print_vector(vector <char> &x){
	if(x.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void print_grid(vector<vector<char>> &y){
	if(y.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<y.size();i++){
		print_vector(y[i]);
	}
	cout<<endl;
}

int box_number(int row, int col){
	if(row>=0 && row<=2){
		if(col>=0 && col<=2){
			return 1;
		}
		if(col>=3 && col<=5){
			return 2;
		}
		if(col>=6 && col<=8){
			return 3;
		}
	}
	if(row>=3 && row<=5){
		if(col>=0 && col<=2){
			return 4;
		}
		if(col>=3 && col<=5){
			return 5;
		}
		if(col>=6 && col<=8){

		}	return 6;
	}
	if(row>=6 && row<=8){
		if(col>=0 && col<=2){
			return 7;
		}
		if(col>=3 && col<=5){
			return 8;
		}
		if(col>=6 && col<=8){
			return 9;
		}		
	}
}

bool isnum(char x){
	if((int)(x-'0')>=0 && (int)(x-'0')<=9){
		return true;
	}
	return false;
}

void update_A(vector<vector<char>> &A,vector<vector<char>> &ans, vector<vector<bool>> &horizontally_available,vector<vector<bool>> &vertically_available,vector<vector<bool>> &boxes,int row,int col){
	if(row>=9 && col==0){
		//cout<<"finally"<<endl;
		//cout<<row<<" "<<col<<endl;
		//print_grid(ans);
		A=ans;
		return;
	}
	else if(isnum(ans[row][col])==true){
		//cout<<"here to go next:"<<"row:"<<row<<"col:"<<col<<endl;
		if(col==8){
			//cout<<"new row"<<endl;
			// row++;
			update_A(A,ans,horizontally_available,vertically_available,boxes,row+1,0);
		}
		else{
			//cout<<"new col"<<endl;
			update_A(A,ans,horizontally_available,vertically_available,boxes,row,col+1);
		}
	}
	else{
		for(int i=1;i<=9;i++){			
			//cout<<"Looped"<<endl;
			if(horizontally_available[row+1][i]==true && vertically_available[col+1][i]==true && boxes[box_number(row,col)][i]==true){
				//cout<<"inside and row:"<<row<<" col:"<<col<<" i:"<<i<<endl;
				//cout<<"ans[row][col]: "<<" row:"<<row<<" col:"<<col<<" ans[row][col]:"<<ans[row][col]<<endl;
				horizontally_available[row+1][i]=false;
				vertically_available[col+1][i]=false;
				boxes[box_number(row,col)][i]=false;
				char temp=ans[row][col];
				ans[row][col]=(char)('0'+i);
				//print_grid(ans);
				if(col==8){
					//cout<<"new row"<<endl;
					update_A(A,ans,horizontally_available,vertically_available,boxes,row+1,0);
				}
				else{
					//cout<<"new col"<<endl;
					update_A(A,ans,horizontally_available,vertically_available,boxes,row,col+1);
				}
				ans[row][col]=temp;
				horizontally_available[row+1][i]=true;
				vertically_available[col+1][i]=true;
				boxes[box_number(row,col)][i]=true;
			}
		}
	}
	return;
}



void solveSudoku(vector<vector<char>> &A) {
	vector<vector<bool>> horizontally_available;
	vector<vector<bool>> vertically_available;
	vector<vector<bool>> boxes;
	vector <bool> temp;
	vector<vector<char>> ans=A;
	//print_grid(ans);
	//cout<<A.size()<<endl;
	for(int i=0;i<A[0].size()+1;i++){
		temp.push_back(true);
	}
	for(int i=0;i<A[0].size()+1;i++){
		horizontally_available.push_back(temp);
		vertically_available.push_back(temp);
		boxes.push_back(temp);
	}
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			if(isnum(A[i][j])==true){
				horizontally_available[i+1][A[i][j]-'0']=false;
				vertically_available[j+1][A[i][j]-'0']=false;
				boxes[box_number(i,j)][A[i][j]-'0']=false;
			}
		}
	}
	//print_grid_bool(horizontally_available);
	//print_grid_bool(vertically_available);
	//print_grid_bool(boxes);
	update_A(A,ans,horizontally_available,vertically_available,boxes,0,0);
}

int main(){
	vector<vector<char>>A;
	int i;
	char x;
	vector <char> temp;
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}
	A.push_back(temp);
	temp.clear();
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}	
	A.push_back(temp);
	temp.clear();
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}
	A.push_back(temp);
	temp.clear();
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}
	A.push_back(temp);
	temp.clear();
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}
	A.push_back(temp);
	temp.clear();
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}
	A.push_back(temp);
	temp.clear();
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}
	A.push_back(temp);
	temp.clear();
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}
	A.push_back(temp);
	temp.clear();
	for(i=0;i<9;i++){
		cin>>x;
		temp.push_back(x);
	}
	A.push_back(temp);
	temp.clear();
	print_grid(A);	
	solveSudoku(A);
	cout<<"Solution: "<<endl;
	print_grid(A);
	return 0;
}