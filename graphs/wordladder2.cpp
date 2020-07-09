#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_vec(vector <string> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void print_vectors(vector <vector <string>> &x){
	for(int i=0;i<x.size();i++){
		print_vec(x[i]);
	}
	cout<<endl;
}

struct Undirected_Graph_Node{
	int label;
	vector <Undirected_Graph_Node*> neighbours;
	Undirected_Graph_Node(int x){
		this->label=x;
	}
};

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
	if(count==1){
		return true;
	}
	return false;
}

void update_ans(vector <string> &dict,unordered_map <int,vector<int>> &umap,int child,vector <string> &ans,vector <vector<string>> &ultimateans){
	if(umap[child].size()==0){
		vector <string> temp=ans;
		reverse(temp.begin(),temp.end());
		ultimateans.push_back(temp);
		return;
	}
	int i,j,k;
	for(i=0;i<umap[child].size();i++){
		ans.push_back(dict[umap[child][i]]);
		update_ans(dict,umap,umap[child][i],ans,ultimateans);
		ans.erase(ans.end()-1);
	}
	return;
}

vector <string> revamp_dict(string &start, string &end, vector<string> &dict){
	unordered_set <string> uset;
	for(int i=0;i<dict.size();i++){
		if(uset.find(dict[i])==uset.end()){
			uset.insert(dict[i]);
		}
	}
	dict.clear();
	for(auto x: uset){
		if(x!=start && x!=end){
			dict.push_back(x);
		}
	}
	return dict;
}

vector <vector<string>> findLadders(string start, string end, vector<string> &dict){
	if(start==end){
		vector <string> ans;
		ans.push_back(start);
		vector <vector <string>> ultimateans;
		ultimateans.push_back(ans);
		return ultimateans;
	}
	if(isdist1(start,end)==true){
		vector <string> ans;
		ans.push_back(start);
		ans.push_back(end);
		vector <vector <string>> ultimateans;
		ultimateans.push_back(ans);
		return ultimateans;	
	}
	dict =revamp_dict(start,end,dict);
	dict.insert(dict.begin(),start);
	dict.push_back(end);
	vector <Undirected_Graph_Node*> vec(dict.size());
	int i,j,k;
	for(i=0;i<vec.size();i++){
		vec[i]= new Undirected_Graph_Node(i);
	}
	//create the graph
	for(i=0;i<dict.size();i++){
		for(j=i+1;j<dict.size();j++){
			if(isdist1(dict[i],dict[j])==true){
				vec[i]->neighbours.push_back(vec[j]);
				vec[j]->neighbours.push_back(vec[i]);
			}
		}
	}

	//apply BFS by maintaining parent nodes
	unordered_map <int,vector<int>> umap;
	queue <Undirected_Graph_Node*> q;
	//vector <int> visited(vec.size(),0);//0 for unvisited, 1 for inside queue, 2 for outside queue and visited;
	vector <int> dist(vec.size(),INT_MAX);
	q.push(vec[0]);
	//visited[0]=1;
	dist[0]=0;
	while(q.empty()==false){
		Undirected_Graph_Node *p=q.front();
		q.pop();
		for(i=0;i<p->neighbours.size();i++){
			if(dist[p->neighbours[i]->label]==INT_MAX){
				dist[p->neighbours[i]->label]=dist[p->label]+1;
				q.push(p->neighbours[i]);
				umap[p->neighbours[i]->label].push_back(p->label);
			}
			else if(dist[p->neighbours[i]->label]!=INT_MAX && dist[p->neighbours[i]->label]==dist[p->label]+1){
				if(find(umap[p->neighbours[i]->label].begin(),umap[p->neighbours[i]->label].end(),p->label)==umap[p->neighbours[i]->label].end()){
				    umap[p->neighbours[i]->label].push_back(p->label);	
				}	
			}
		}
	}
	//check the distance of target.
	//cout<<dist[dist.size()-1]<<endl;


	//buil the answer strings
	vector <vector <string>>ultimateans;
	vector <string> ans;
	if(dist[dist.size()-1]==INT_MAX){
		return ultimateans;
	}
	ans.push_back(dict[dict.size()-1]);
	update_ans(dict,umap,dist.size()-1,ans,ultimateans);
	return ultimateans;
}

int main(){
	string A="hit";
	string B="cog";
	vector <string> midvals={"hot","dot","dog","lot","log"};
	vector <vector <string>> ans=findLadders(A,B,midvals);
	print_vectors(ans);
	return 0;
}
