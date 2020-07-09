#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node{
	char letter;
	bool end;
	vector <node*> children;
	node(char x){
		this->letter=x;
		this->end=false;
	}
};

struct stone{
	int index;
	int weight;
};

bool comparefunc(stone &a,stone &b){
	if(a.weight!=b.weight){
		return a.weight>b.weight;
	}
	else{
		return a.index<b.index;
	}
}

void print_trie(node *trie,string &temp){
	temp.push_back(trie->letter);
	if(trie->children.size()==0){
		cout<<temp<<endl;
		return;
	}
	if(trie->end==true){
		cout<<temp<<endl;
	}
	int i,j,k;
	for(i=0;i<trie->children.size();i++){
		print_trie(trie->children[i],temp);
		temp.erase(temp.end()-1);
	}
	return;
}

node *construct_trie(string &A){
	node *trie=new node('#');
	node *temp,*p,*q,*r;
	int i,j,k;
	i=0;
	while(i<A.size()){
		j=i;
		p=trie;
		while(j<A.size() && A[j]!='_'){
			k=0;
			int flag=0;
			while(k<p->children.size()){
				if(p->children[k]->letter==A[j]){
					p=p->children[k];
					flag++;
					break;
				}
				k++;
			}
			if(flag==0){
				temp=new node(A[j]);
				p->children.push_back(temp);
				p=temp;
			}
			j++;
		}
		p->end=true;
		i=j+1;
	}
	return trie;
}

int exists(node *trie,string &A){
	node *p,*q,*r;
	p=trie;
	int i,j,k;
	for(i=0;i<A.size();i++){
		int flag=0;
		for(j=0;j<p->children.size();j++){
			if(p->children[j]->letter==A[i]){
				p=p->children[j];
				flag++;
				break;
			}
		}
		if(flag==0){
			return 0;
		}
	}
	if(p->end==true){
		return 1;
	}
	return 0;
}

int score(node *trie, string &x){
	string temp;
	int points=0;
	int i,j,k;
	i=0;
	while(i<x.size()){
		j=i;
		temp.clear();
		while(j<x.size() && x[j]!='_'){
			temp.push_back(x[j]);
			j++;
		}
		points+=exists(trie,temp);
		i=j+1;
	}
	return points;
}

vector <int> solve(string A, vector<string> &B){
	vector <int> ans;
	vector <stone> x;
	stone temp;
	node *trie=construct_trie(A);
	int i,j,k;
	for(i=0;i<B.size();i++){
		//cout<<B[i]<<" "<<score(trie,B[i])<<endl;
		temp.weight=score(trie,B[i]);
		temp.index=i;
		x.push_back(temp);
	}
	sort(x.begin(),x.end(),comparefunc);
	for(i=0;i<x.size();i++){
		ans.push_back(x[i].index);
	}
	return ans;
}

int main(){
	string A="cool_ice_wifi";
	vector <string> B={"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
	vector <int> ans=solve(A,B);
	cout<<"answer: ";	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}