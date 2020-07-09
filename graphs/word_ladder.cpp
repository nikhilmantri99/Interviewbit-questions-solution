#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Undirected_Graph_Node{
	int label;
	vector <Undirected_Graph_Node*> neighbours;
	Undirected_Graph_Node(int x){
		this->label=x;
	}
};

//create an undirected graph(not a directed one with edges between words that have a distance of 1),i.e they are interconvertible,
//then traverse the graph from the source word to the target. return lenght of shorted path using bfs.

//Take care of the trivial cases as seen in function solve which otherwise give TLE. 

bool isdist1(string &a, string &b){
	if(a.size()!=b.size()){
		return false;
	}
	int i,count=0;
	for(i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			count++;
		}
	}
	if(count<=1){
		return true;
	}
	return false;
}

int BFS_dist(vector <Undirected_Graph_Node*> &vec,vector <string> &C){
	vector <int> dist(vec.size(),INT_MAX);
	Undirected_Graph_Node *p;
	vector <bool> visited(vec.size(),false);
	dist[0]=0;
	visited[0]=true;
	queue <Undirected_Graph_Node*> process;
	process.push(vec[0]);
	while(process.empty()==false){
		p=process.front();
		process.pop();
		//visited[p->label]=true;
		for(int i=0;i<p->neighbours.size();i++){
			if(visited[p->neighbours[i]->label]==false){
				dist[p->neighbours[i]->label]=dist[p->label]+1;
				cout<<"distance of"<<C[p->neighbours[i]->label]<<"="<<dist[p->neighbours[i]->label]<<endl;
				visited[p->neighbours[i]->label]=true;
				process.push(p->neighbours[i]);
			}
		}
	}
	return dist[dist.size()-1];
}

int create_graph_and_return_minimum_distance(string &A,string &B,vector <string> &C ){
	C.insert(C.begin(),A);
	C.push_back(B);
	vector <Undirected_Graph_Node*> vec(C.size());
	int i,j,k;
	for(i=0;i<vec.size();i++){
		vec[i]=new Undirected_Graph_Node(i);
	}
	for(i=0;i<C.size();i++){
		cout<<"forward neigbours of "<<C[i]<<":"<<endl;
		for(j=i+1;j<C.size();j++){
			if(isdist1(C[i],C[j])==true){
				cout<<C[j]<<endl;
				vec[i]->neighbours.push_back(vec[j]);
				vec[j]->neighbours.push_back(vec[i]);
			}
		}
	}
	return BFS_dist(vec,C);
}


int solve(string A, string B, vector<string> &C) {
	//important base cases
	if(A==B){
	    return 1;
	}
	if(isdist1(A,B)==true){
	    return 2;
	}
	int val=create_graph_and_return_minimum_distance(A,B,C);
	if(val==INT_MAX){
		return 0;
	}
	else return val+1;
}

int main(){
	string A="ymain";
	string B="oecij";
	vector <string> midvals={"ymann", "yycrj", "ymcnj", "yzcrj", "yycij", "xecij", "yecij", "ymanj", "yzcnj"};
	cout<<solve(A,B,midvals)<<endl;
	return 0;	
}

