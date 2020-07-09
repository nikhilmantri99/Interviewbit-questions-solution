#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//The n-queens puzzle is the problem of placing n queens on an n*n chessboard
//such that no two queens attack each other

struct Queen_address{
	int r;
	int c;
};

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

bool is_safe(int R, int C, vector <Queen_address> &queens){
	if(queens.size()==0){
		return true;
	}
	int i,j,k;
	for(i=0;i<queens.size();i++){
		if(queens[i].r==R || queens[i].c==C){
			return false;
		}
		else{
			double m=(double)(queens[i].r-R)/(double)(queens[i].c-C);
			if(m==1.00 || m==-1.00){
				return false;
			}
		}
	}
	return true;
}

void update_ans(int n, int row,vector <vector <string>> &ans, vector <string> &temp, vector <Queen_address> &queens){
	if(queens.size()==n){
		cout<<"answer grid:"<<endl;
		print_grid(temp);
		ans.push_back(temp);
		return;
	}
	if(row>=n){
		return;
	}
	int i,j,k;
	for(i=0;i<temp[0].size();i++){
		if(is_safe(row,i,queens)){
			temp[row][i]='Q';
			Queen_address t;
			t.r=row;
			t.c=i;
			queens.push_back(t);
			update_ans(n,row+1,ans,temp,queens);
			temp[row][i]='.';
			queens.erase(queens.end()-1);
		}
	}
	return;
}

vector<vector<string> > solveNQueens(int A) {
    int n=A;
    vector <vector <string>> ans;
    vector <string> temp(n,string(n,'.'));
    vector <Queen_address> queens;
    cout<<"our grid:"<<endl;
    print_grid(temp);
    update_ans(n,0,ans,temp,queens);
    return ans;
}

int main(){
	int A;
	cin>>A;
	vector<vector<string>> ans= solveNQueens(A);
	return 0;
}