#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//The n-queens puzzle is the problem of placing n queens on an n*n chessboard
//such that no two queens attack each other

struct Queen_address{
	int r;
	int c;
};

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


void print_grid(vector <string> &y){
	if(y.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<y.size();i++){
		cout<<y[i]<<endl;
	}
	cout<<endl;
}

void mark_r_c_d(int row, int col, vector<vector<bool>> &y,bool status){
	int n=y.size();
	int i,j;
	for(i=0;i<n;i++){
		y[i][col]=status;
		y[row][i]=status;
	}
	i=row;
	j=col;
	while(i>=0 && j>=0){
		y[i][j]=status;
		i--;
		j--;
	}
	i=row;
	j=col;
	while(i<n && j<n){
		y[i][j]=status;
		i++;
		j++;
	}
	i=row;
	j=col;
	while(i>=0 && i<n && j>=0 && j<n){
		y[i][j]=status;
		i--;
		j++;
	}
	i=row;
	j=col;
	while(i>=0 && i<n && j>=0 && j<n){
		y[i][j]=status;
		i++;
		j--;
	}
}

void mark_grid(vector<vector<bool>> &y,bool status){
	int n=y.size();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			y[i][j]=status;
		}
	}
}	

void update_ans(vector<vector<bool>> &attack_status,vector <vector<string>> &all,vector <string> &ans,vector<Queen_address> &QA,int row,int dimension,int NQueens){
	if(NQueens==dimension){
		// cout<<"solution:"<<endl;
		// print_grid(ans);
		all.push_back(ans);
		return;
	}
	else if(row<dimension && NQueens<dimension){
		for(int i=0;i<dimension;i++){
			if(attack_status[row][i]==true && ans[row][i]=='.'){
				//cout<<"row: "<<row<<" col: "<<i<<" We place a Queen. "<< endl;
				ans[row][i]='Q';
				Queen_address temp;
				temp.r=row;
				temp.c=i;
				QA.push_back(temp);

				mark_r_c_d(row,i,attack_status,false);
				
				//print_grid_bool(attack_status);
				//cout<<endl;

				update_ans(attack_status,all,ans,QA,row+1,dimension,NQueens+1);
				
				ans[row][i]='.';
				QA.erase(QA.end()-1);
				//We need to do it following way because blindly doing mark_r_c_d(row, i , attack_status, true) may overwrite other queens attack points
				mark_grid(attack_status,true);
				for(int j=0;j<QA.size();j++){
					mark_r_c_d(QA[j].r,QA[j].c,attack_status,false);
				}
			}
		}
	}
	return;
}

vector<vector<string>> solveNQueens(int A){
	vector<vector<bool>> attack_status;
	vector <bool> use_case;
	vector <vector<string>> all;
	vector <string> ans;
	vector <Queen_address> QA;
	string temp;
	//empty cell='.', Queen='.'
	int i;
	for(i=0;i<A;i++){
		use_case.push_back(true);
		temp.push_back('.');
	}
	for(i=0;i<A;i++){
		ans.push_back(temp);
		attack_status.push_back(use_case);
	}
	// print_grid_bool(attack_status);
	// mark_r_c_d(2,1,attack_status,false);
	// cout<<endl;	
	// print_grid_bool(attack_status);
	update_ans(attack_status,all,ans,QA,0,A,0);
	return all;
}

int main(){
	int A;
	cin>>A;
	vector<vector<string>> ans= solveNQueens(A);
	return 0;
}