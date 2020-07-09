#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int nchoc(int A, vector<int> &B) {
	int modulo=pow(10,9)+7;
	int max_choc=0,i,j,k;
	priority_queue <int> pq;
	for(i=0;i<B.size();i++){
		pq.push(B[i]);
	}
	while(A>0){
		A--;
		max_choc=(max_choc%modulo+pq.top()%modulo)%modulo;
		max_choc=max_choc%modulo;
		int temp=pq.top();
		pq.pop();
		temp=temp/2;
		pq.push(temp);
	}
	return max_choc%modulo;
}

int main(){
	vector <int> B={5,6};
	int A=3;
	cout<<nchoc(A,B)<<endl;
	return 0;
}
