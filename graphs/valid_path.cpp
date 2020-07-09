#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_grid(vector <vector<int>> &grid){
	int i,j;
	for(i=0;i<grid.size();i++){
		for(j=0;j<grid[0].size();j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isvalid(int x, int y,vector <vector<int>> &grid){
	if(x>=grid[0].size() ||x<0 || y>=grid.size() || y<0){
		return false;
	}
	return true;
}

bool isInCircle(int x, int y,int centre_x,int centre_y, int R, vector <vector<int>> &grid){
	if(isvalid(x,y,grid)==false){
		return false;
	}

	double dist=sqrt((double)(pow(centre_y-y,2)+pow(centre_x-x,2)));
	if(dist<=((double)R)){
		return true;
	}
	else{
		return false;
	}
}

void DFS(int x,int y, int centre_x,int centre_y, int R, vector <vector <int>> &grid,int color){
	if(isvalid(x,y,grid)==false){
		return;
	}
	if(isInCircle(x,y,centre_x,centre_y,R,grid)==false){
		return;
	}
	if(grid[y][x]==color){
		return;
	}
	cout<<"coloring x:"<<x<<" y:"<<y<<endl;
	grid[y][x]=color;
	DFS(x+1,y,centre_x,centre_y,R,grid,color);
	DFS(x-1,y,centre_x,centre_y,R,grid,color);
	DFS(x,y+1,centre_x,centre_y,R,grid,color);
	DFS(x,y-1,centre_x,centre_y,R,grid,color);
	DFS(x+1,y+1,centre_x,centre_y,R,grid,color);
	DFS(x-1,y-1,centre_x,centre_y,R,grid,color);
	DFS(x+1,y-1,centre_x,centre_y,R,grid,color);
	DFS(x-1,y+1,centre_x,centre_y,R,grid,color);
}

bool search_for_route(int initial_x,int initial_y,int final_x,int final_y, vector <vector <int>> &grid){
	if(isvalid(initial_x,initial_y,grid)==false){
		return false;
	}
	if(grid[initial_y][initial_x]==-1){
		return false;
	}
	if(initial_x==final_x && initial_y==final_y){
		return true;
	}
	if(grid[initial_y][initial_x]==-1 || grid[initial_y][initial_x]>0){
		return false;
	}
	grid[initial_y][initial_x]=-1;
	int truth_count=0;
	bool truth;
	truth=search_for_route(initial_x+1,initial_y,final_x,final_y,grid);
	if(truth==true) truth_count++;

	truth=search_for_route(initial_x-1,initial_y,final_x,final_y,grid);
	if(truth==true) truth_count++;

	truth=search_for_route(initial_x,initial_y+1,final_x,final_y,grid);
	if(truth==true) truth_count++;

	truth=search_for_route(initial_x,initial_y-1,final_x,final_y,grid);
	if(truth==true) truth_count++;

	truth=search_for_route(initial_x+1,initial_y+1,final_x,final_y,grid);
	if(truth==true) truth_count++;

	truth=search_for_route(initial_x+1,initial_y-1,final_x,final_y,grid);
	if(truth==true) truth_count++;

	truth=search_for_route(initial_x-1,initial_y+1,final_x,final_y,grid);
	if(truth==true) truth_count++;

	truth=search_for_route(initial_x-1,initial_y-1,final_x,final_y,grid);
	if(truth==true) truth_count++;

	if(truth_count>0){
		return true;
	}
	return false;

}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
	int x=A,y=B,N=C,R=D;
	vector <vector <int>> grid(B+1,vector <int> (A+1,0));
	//color the non_visitable co-ordinate cells as -1;
	int i,j,k;
	for(i=0;i<E.size();i++){
		DFS(E[i],F[i],E[i],F[i],R,grid,i+1);
	}
	cout<<grid.size()<<" "<<grid[0].size()<<endl;
	print_grid(grid);
	bool truth=search_for_route(0,0,x,y,grid);
	if(truth==true){
		return "YES";
	}
	else{
		return "NO";
	}
}

int main(){
	int x=51,y=41,N=6,R=9;
	vector <int> A={ 2, 2, 37, 8, 5, 36 };
	vector <int> B={10, 3, 31, 12, 5, 40};
	cout<<solve(x,y,N,R,A,B)<<endl;
	return 0;
}
