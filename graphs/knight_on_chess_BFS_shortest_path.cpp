#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isvalid(int i,int j,vector <vector<bool>> &visited){
    if(i<0||i>=visited.size()||j<0||j>=visited[0].size()){
        return false;
    }
    return true;
}
// I-2, J+1
// I-2, J-1

// I-1, J+2
// I-1, J-2

// I+1, J+2
// I+1, J-2

// I+2, J+1
// I+2, J-1

struct node{
    int x;
    int y;
};

int update_minval(vector <vector <int>> &moves,vector <vector<bool>> &visited,int i,int j, int destination_i,int destination_j){
    if(isvalid(i,j,visited)==false){
        return -1;
    }
    visited[i][j]=true;
    int k,l;
    queue <node> q;
    node temp;
    temp.x=i;
    temp.y=j;
    q.push(temp);
    int steps=0;
    vector <vector <int>> dist(visited.size(),vector <int> (visited[0].size(),INT_MAX));
    dist[i][j]=0;
    while(q.empty()==false){
        int k=q.front().x;
        int l=q.front().y;
        q.pop();
        for(int m=0;m<moves.size();m++){
            if(isvalid(k+moves[m][0],l+moves[m][1],visited)==true){
                if(visited[k+moves[m][0]][l+moves[m][1]]==false){
                    visited[k+moves[m][0]][l+moves[m][1]]=true;
                    temp.x=k+moves[m][0];
                    temp.y=l+moves[m][1];
                    dist[k+moves[m][0]][l+moves[m][1]]=dist[k][l]+1;
                    q.push(temp);
                    if(k+moves[m][0]==destination_i && l+moves[m][1]==destination_j){
                        break;
                    }
                }
            }
        }
    }
    if(visited[destination_i][destination_j]==true){
        return dist[destination_i][destination_j];
    }
    else{
        return -1;
    }
    
}

int knight(int A, int B, int C, int D, int E, int F) {
    vector <vector<bool>> visited(A,vector <bool> (B,false));
    int minval=INT_MAX;
    int steps=0;
    vector <vector<int>> moves={{+2,+1}, {+2,-1}, {-2,+1}, {-2,-1}, {+1,+2}, {+1,-2}, {-1,+2}, {-1, -2}};
    return update_minval(moves,visited,C-1,D-1,E-1,F-1);
}
