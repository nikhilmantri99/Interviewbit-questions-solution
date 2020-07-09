#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node{
	char c;
	bool end;
	vector <node *> children;
	node(char x){
		this->c=x;
		this->end=false;
	}
};

struct brick{
    int weight;
    int index;
    bool operator <(const brick &t)const{
        if(weight!=t.weight) return weight<t.weight;
        else return index>t.index;
    }
};

node *construct_trie(string &A){
	node *root=new node('#');
	node *p=root;
	for(int i=0;i<A.size();i++){
		if(A[i]=='_'){
			p->end=true;
			p=root;
		}
		else if(p->children.size()==0){
			node *temp=new node(A[i]);
			p->children.push_back(temp);
			p=temp;
		}
		else{
			int j=0,flag=0;
			while(j<(p->children.size())){
				if(p->children[j]->c==A[i]){
					p=p->children[j];
					flag++;
					break;

				}
				j++;
			}
			if(flag==0){
				node *temp=new node(A[i]);
				p->children.push_back(temp);
				p=temp;
			}
		}
	}
	p->end=true;
	return root;
}

void print_string(string &x, int i,int j){
	string temp;
	for(int k=i;k<j;k++){
		temp.push_back(x[k]);
	}
//	cout<<temp<<endl;
}

void print_trie(string &temp,node *root){
	temp.push_back(root->c);
	if(root->children.size()==0 && root->end==true){
		//cout<<temp<<endl;
		return;
	}
	else{
		if(root->end==true){
			//cout<<temp<<endl;
		}
		for(int i=0;i<root->children.size();i++){
			print_trie(temp,root->children[i]);
			temp.erase(temp.end()-1);
		}
	}
}

int score_generator(string &x, int lower, int upper, node *root){
	print_string(x,lower,upper);
	if(lower>=upper){
		return 0;
	}
	node *p=root;
	int found=0;
	for(int i=0;i<root->children.size();i++){
		if(root->children[i]->c==x[lower]){
			p=root->children[i];
			//q=root->children[i];
			found++;
			break;
		}
	}
	if(found==0){
		return 0;
	}
	if(found>0 && upper-lower==1 && p->end==true){
		return 1;
	}
	//cout<<"here"<<endl;
	int i,j;
	for(i=lower+1;i<upper;i++){
		if(p->children.size()==0){
			//cout<<"here2"<<endl;
			return 0;
		}
		for(j=0;j<p->children.size();j++){
			found=0;
			if(p->children[j]->c==x[i]){
				found++;
				p=p->children[j];
			}
			if(found==0){
				//cout<<"here3"<<endl;
				return 0;
			}
		}
	}
	if(p->c==x[upper-1] && (p->end==true||p->children.size()==0)){
		//cout<<"here4"<<endl;
		return 1;
	}
	//cout<<"here5"<<endl;
	return 0;
}

int score(node *root,string &x){
	int i,j,value=0;
	i=0;
	//cout<<x<<endl;
	while(i<x.size()){
		j=i;
		while(j<x.size() && x[j]!='_'){
			j++;
		}
		print_string(x,i,j);
		int temp=score_generator(x,i,j,root);
		//cout<<"temp: "<<temp<<endl;
		value=value+temp;
		//cout<<"value: "<<value<<endl;
		i=j+1;
	}
	//cout<<value<<endl;
	return value;
}



vector<int> Solution::solve(string A, vector<string> &B) {
    node *head=construct_trie(A);
    //string temp;
    //temp.clear();
    //print_trie(temp,head);
    //temp.clear();
    //print_trie(temp,head);
    priority_queue <brick> pq;
    for(int i=0;i<B.size();i++){
        brick b;
        b.index=i;
        b.weight=score(head,B[i]);
        pq.push(b);
    }
    vector <int> ans;
    while(pq.empty()==false){
        ans.push_back(pq.top().index);
        pq.pop();
    }
    return ans;
}


int main(){
	string A="cool_ice_wifi";
	node *root=construct_trie(A);
	// cout<<root->c<<endl;
	// cout<<root->children.size()<<endl;
	// cout<<(root->children[0]->c)<<endl;
	// cout<<(root->children[0]->children.size())<<endl;
	// cout<<(root->children[0]->children[0]->c)<<endl;
	// cout<<(root->children[0]->children[0]->children.size())<<endl;
	string temp;
	//print_trie(temp,root);
	//print_trie(temp,root);
	//print_trie(temp,root);	
	string B="cool_ice_wifi";
	string C="ice";
	//cout<<score_generator(C,0,C.size(),root)<<endl;
	//print_trie(temp,root);
	//cout<<score_generator(C,0,C.size(),root)<<endl;
	//print_trie(temp,root);
	cout<<score(root,B)<<endl;
	return 0;
}



