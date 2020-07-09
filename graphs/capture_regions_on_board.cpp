#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isvalid(int i,int j, vector<vector<char> > &A){
    if(i>=0 && i<A.size() && j>=0 && j<A[0].size()){
        return true;
    }
    return false;
}

//we could have returned false at the first instant we found false. But note that it was necessary to mark all Os
//in the current region as visited so we had to ensure that entire DFS was carried out completely.
//and hence we return the bool value this way. 

bool explore (int i,int j,vector<vector<char> > &A,vector <vector<bool>> &visited){
    //cout<<"exploring i,j:"<<i<<","<<j<<endl;
    visited[i][j]=true;
    int false_count=0;
    bool truth;
    if(isvalid(i-1,j,A)==false){
        //cout<<"here"<<endl;
        false_count++;
    }
    else if(visited[i-1][j]==false && A[i-1][j]=='O'){
        //cout<<"here1"<<endl;
        truth=explore(i-1,j,A,visited);
        if(truth==false){
            false_count++;
        }
    }
    
    if(isvalid(i+1,j,A)==false){
        //cout<<"here2"<<endl;
        false_count++;
    }
    else if(visited[i+1][j]==false && A[i+1][j]=='O'){
        //cout<<"here3"<<endl;
        truth=explore(i+1,j,A,visited);
        if(truth==false){
            false_count++;
        }
    }
     
    if(isvalid(i,j-1,A)==false){
        //cout<<"here4"<<endl;
        false_count++;
    }
    else if(visited[i][j-1]==false && A[i][j-1]=='O'){
        //cout<<"here5"<<endl;
        truth=explore(i,j-1,A,visited);
        if(truth==false){
            false_count++;
        }
    }
    
    if(isvalid(i,j+1,A)==false){
        //cout<<"here6"<<endl;
        false_count++;
    }
    else if(visited[i][j+1]==false && A[i][j+1]=='O'){
        //cout<<"here7"<<endl;
        truth=explore(i,j+1,A,visited);
        if(truth==false){
            false_count++;
        }
    }
    
    if(false_count>0){
       // cout<<"here8"<<endl;
        return false;
    }
    return true;
}

void color_region(int i,int j,vector<vector<char> > &A){
    if(i<0 || i>=A.size() || j<0 || j>=A[0].size()){
        return;
    }
    if(A[i][j]=='X'){
        return;
    }
    A[i][j]='X';
    color_region(i-1,j,A);
    color_region(i+1,j,A);
    color_region(i,j-1,A);
    color_region(i,j+1,A);
}

void solve(vector<vector<char> > &A) {
    int i,j;
    vector <vector <bool>> visited(A.size(),vector <bool> (A[0].size(),false));
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            if(A[i][j]=='O' && visited[i][j]==false){
                //cout<<"call i,j:"<<i<<","<<j<<endl;
                if(explore(i,j,A,visited)==true){
                    color_region(i,j,A);
                }
            }
        }
    }
    return;
}

int main(){
    vector <vector <char>> A={{'X','O','X'},{'X','O','X'},{'X','O','X'}};
    solve(A);
    return 0;
}
