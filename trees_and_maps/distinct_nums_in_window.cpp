#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

vector <int> dNums(vector<int> &A, int B) {
	vector <int> ans;
	if(B>A.size()){
		return ans;
	}
	int i,j,k;
	map <int,int> m;
	for(i=0;i<B;i++){
		if(m.find(A[i])==m.end()){
			m[A[i]]=1;
		}
		else{
			m[A[i]]++;
		}
	}
	ans.push_back(m.size());
	for(i=B;i<A.size();i++){
		m[A[i-B]]--;
		if(m[A[i-B]]==0){
			m.erase(A[i-B]);
		}
		if(m.find(A[i])==m.end()){
			m[A[i]]=1;
		}
		else{
			m[A[i]]++;
		}
		ans.push_back(m.size());
	}
	return ans;
}

int main(){
	vector <int> A={1, 2, 1, 3, 4, 3};
	int B=3;
	vector <int> ans=dNums(A,B);
	print_vector(ans);
	return 0;
}
