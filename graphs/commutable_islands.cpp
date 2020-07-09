#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//We apply Kruskal's minimum spanning tree algorithm to find the minimum overall cost so that all islands or nodes
//are connected. We first sort the edges according to their weights. and pick each edge one by one. If both the ends of an 
//edge belong to the same subset then we discard that edge . because we do not want to create a cycle. obviously.
//For that we use the union find approach to find if the nodes belong to already connected subset. 

bool comparefunc(vector<int> &a, vector <int> &b){
    return a[2]<b[2];
}

int find_parent(int x,vector <int> &parent){
    if(parent[x]==-1){
        return x;
    }
    return find_parent(parent[x],parent);
}

void Union(int x, int y, vector <int> &parent){
    int xset=find_parent(x,parent);
    int yset=find_parent(y,parent);
    if(xset!=yset){
        parent[xset]=yset;//avoid creating self-loop;
    }
}

int find_if_same_subset(int x, int y, vector <int> &parent){
    int x_parent=find_parent(x,parent);
    int y_parent=find_parent(y,parent);
    if(x_parent==y_parent){
        return 1;
    }
    else{
        return 0;
    }
}

int solve(int A, vector<vector<int> > &B) {
    sort(B.begin(),B.end(),comparefunc);
    vector <int> parent(A+1,-1);
    int bridges=0,sum=0,i,j,k;
    sum+=B[0][2];
    Union(B[0][0],B[0][1],parent);
    for(i=1;i<B.size();i++){
        if(find_if_same_subset(B[i][0],B[i][1],parent)==0){
            sum+=B[i][2];
            Union(B[i][0],B[i][1],parent);
        }
    }
    return sum;
}

int main(){
    int A = 4;
    vector <vector <int>>B ={  {1, 2, 1},
            {2, 3, 2},
            {3, 4, 4},
            {1, 4, 3}
    };
    cout<<solve(A,B)<<endl;
    return 0;
}