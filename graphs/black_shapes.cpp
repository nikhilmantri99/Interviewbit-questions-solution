#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void visit(vector<string> &A,vector <vector <bool>> &visited,int i,int j){
    if(i<0||i>=A.size()||j<0||j>=A[0].size()){
        return;
    }
    if(A[i][j]=='O'){
        visited[i][j]=true;
        return;
    }
    if(A[i][j]=='X' && visited[i][j]==false){
        visited[i][j]=true;
        visit(A,visited,i+1,j);
        visit(A,visited,i-1,j);
        visit(A,visited,i,j+1);
        visit(A,visited,i,j-1);
    }
    return;
}

int black(vector<string> &A) {
    vector <vector <bool>> visited (A.size(),vector<bool>(A[0].size(),false)); 
    int count=0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]=='O'){
                visited[i][j]=true;
            }
            else if(A[i][j]=='X' && visited[i][j]==false){
                count++;
                visit(A,visited,i,j);
            }
        }
    }
    return count;
}

int main(){
	vector <string> A={"OOOXOOO","OOXXOXO","OXOOOXO"};
	cout<<black(A)<<endl;
	return 0;
}