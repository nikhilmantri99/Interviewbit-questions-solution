#include <bits/stdc++.h>
#include <iostream>

using namespace std;



void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void sortColors(vector<int> &A) {
	int i,j,k;
	int z=0,o=0,t=0;
	for(i=0;i<A.size();i++){
		if(A[i]==0){
			z++;
		}
		else if(A[i]==1){
			o++;
		}
		else{
			t++;
		}
	}
	A.clear();
	for(i=0;i<z;i++){
		A.push_back(0);
	}
	for(i=0;i<o;i++){
		A.push_back(1);
	}
	for(i=0;i<t;i++){
		A.push_back(2);
	}
	//print_vector(A);
	return;
}

int main(){
	vector <int> A={0,1,2,0,0,1,2};
	sortColors(A);
	return 0;
}
