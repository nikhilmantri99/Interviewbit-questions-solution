#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//classic example to create a directed graph, edge pointing from graph with label prerequiste to label subject
//and then find a cycle in it using a recursion stack and DFS. Go through it. You took two hints, graph and cycle.
//remember how to find a cycle using an array of recursion stack(0 unvisted,1 visited and in stack,2 visited and outside stack) . Nice one deer. 

struct Directed_Graph_node{
	int label;
	vector <Directed_Graph_node*> neighbours;
	Directed_Graph_node(int x){
		this->label=x;
	}
};

bool find_cycle(Directed_Graph_node *node,vector <int> &recursion_stack){
	if(recursion_stack[node->label]==1){
		return false;
	}
	recursion_stack[node->label]=1;
	int i;
	bool truth;
	for(i=0;i<node->neighbours.size();i++){
		if(recursion_stack[node->neighbours[i]->label!=2]){
			truth=find_cycle(node->neighbours[i],recursion_stack);
			if(truth==false){
				return false;
			}
		}
	}
	recursion_stack[node->label]=2;
	return true;
}

bool create_graph_and_check_for_cycle(int A,vector <int> &source,vector <int> & sink){
	int i,j;
	vector <Directed_Graph_node *> vec(A+1);
	cout<<"here"<<endl;
	for(i=0;i<=A;i++){
		vec[i]=new Directed_Graph_node(i);
	}
	cout<<"here"<<endl;	
	for(i=0;i<source.size();i++){
		vec[source[i]]->neighbours.push_back(vec[sink[i]]);
	}
	vector <int> recursion_stack(A+1,0);//0 means unvisited,1 means visited and in recursion stack, 2 means visted and
	bool truth;
	for(i=0;i<vec.size();i++){
		if(recursion_stack[i]==0){
			truth=find_cycle(vec[i],recursion_stack);
			if(truth==false){
				return false;
			}
		}
	}
	return true;
	//out of recursion stack
}

int solve(int A, vector<int> &B, vector<int> &C) {
    if(A==1||A==0){
    	return 1;
    }
    bool truth=create_graph_and_check_for_cycle(A,B,C);
    if(truth==false){
    	return 0;
    }
    return 1;
}

int main(){
	int A;
	vector <int> B={1,2};
	vector <int> C={2,1};
	cout<<solve(A,B,C)<<endl;
	return 0;
}
