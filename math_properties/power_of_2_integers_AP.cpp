#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector <int> isPower(int A) {
	vector <bool> isprime(A+1,true);
	isprime[0]=false;
	isprime[1]=false;
	isprime[2]=true;
	int i,j,k;
	for(i=2;i<isprime.size();i++){
		if(isprime[i]==true){
			for(j=2*i;j<isprime.size();j++){
				isprime[j]=false;
			}
		}
	}
	unordered_map <int,int> umap;
	int minpower=INT_MAX;
	i=2;
	while(i<isprime.size() && A>1){
		if(isprime[i]==true && A%i==0 && A>1){
			if(umap.find(i)==umap.end()){
				umap[i]=0;
			}
			else{
				umap[i]++;
			}
		}
		else{
			i++;
		}
	}
	for(auto x:umap){
		minpower=min(minpower,x.second);
	}
	for(auto x:umap){
		if(x.second%minpower!=0)
	}
}