#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//IMportant question:
//Basically we have to find the largest distance between two nodes of an undirected acyclic graph
// So we select any vertex first(here root),run a BFS and find a node at the farthest distance from it. This is one endpoint
//among the two nodes, now we run BFS starting from this node and find the longest distance of a node. This is our second node
// and the distance is the answer.

// Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes.
// The goal of the problem is to find largest distance between two nodes in a tree.
// Distance between two nodes is a number of edges on a path between the nodes 
//(there will be a unique path between any pair of nodes since it is a tree).
// The nodes will be numbered 0 through N - 1.
// The tree is given as an array P,
// there is an edge between nodes P[i] and i (0 <= i < N). 
//Exactly one of the i’s will have P[i] equal to -1, it will be root node.

struct Multi_Tree_Node{
	int label;
	vector <Multi_Tree_Node*> children;
	Multi_Tree_Node(int x){
		this->label=x;
	}
};

int solve(vector<int> &A){
	vector <Multi_Tree_Node*> vec(A.size());
	int i,j,k;
	for(i=0;i<A.size();i++){
		vec[i]=new Multi_Tree_Node(i);
	}
	Multi_Tree_Node *root;
	for(i=0;i<A.size();i++){
		if(A[i]==-1){
			root=vec[i];
		}
		else{
			//make it an undirected acyclic graph
			vec[min(i,A[i])]->children.push_back(vec[max(i,A[i])]);
			vec[max(i,A[i])]->children.push_back(vec[min(i,A[i])]);
		}
	}
	//In this post, an efficient solution is discussed. 
	//We can find longest path using two BFSs. 
	//The idea is based on the following fact: 
	//If we start BFS from any node x and find a node with the longest distance from x, 
	//it must be an end point of the longest path. It can be proved using contradiction. 
	//So our algorithm reduces to simple two BFSs. First BFS to find an end point of the longest path and 
	//second BFS from this end point to find the actual longest path. 
	//For the proof of why does this algorithm works, there is nice explanation here Proof of correctness: 
	//Algorithm for diameter of a tree in graph theory.
	queue <Multi_Tree_Node*> q;
	vector <int> dist(vec.size(),INT_MAX);
	dist[root->label]=0;
	q.push(root);
	while(q.empty()==false){
		Multi_Tree_Node *p=q.front();
		q.pop();
		for(i=0;i<p->children.size();i++){
			if(dist[p->children[i]->label]==INT_MAX){
				dist[p->children[i]->label]=dist[p->label]+1;
				q.push(p->children[i]);
			}
		}
	}
	int max_distance=INT_MIN;
	int max_node=-1;
	for(i=0;i<dist.size();i++){
		if(dist[i]>max_distance){
			max_distance=dist[i];
			max_node=i;
		}
	}
	vector <int> dist2(vec.size(),INT_MAX);
	q.push(vec[max_node]);
	dist2[max_node]=0;
	max_distance=INT_MIN;
	while(q.empty()==false){
		Multi_Tree_Node *p=q.front();
		q.pop();
		for(i=0;i<p->children.size();i++){
			if(dist2[p->children[i]->label]==INT_MAX){
				dist2[p->children[i]->label]=dist2[p->label]+1;
				q.push(p->children[i]);
			}
		}
	}
	for(i=0;i<dist2.size();i++){
		max_distance=max(max_distance,dist2[i]);
	}
	return max_distance;
}

int main(){
	vector <int> A={-1, 0, 0, 0, 3};
	cout<<solve(A)<<endl;
	return 0;
}