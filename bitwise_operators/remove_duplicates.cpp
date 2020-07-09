#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int removeDuplicates(vector<int> &A){
	int i,j,k;
	int n=A.size();
	//cout<<"n:"<<n<<endl;
	i=0;
	while(i<A.size()-1){
		j=i+1;
		while(A[j]==A[i] && j<A.size()){
			j++;
		}
		//cout<<"i:"<<i<<" j:"<<j<<endl;
		if(j>=i+2){
			A.erase(A.begin()+i+1,A.begin()+j);
		}
		i++;
	}
	//print_vector(A);
	return A.size();
}

int main(){
	vector <int> A={1,1,2,3,4,7,7,8,8,8};
	cout<<removeDuplicates(A)<<endl;
	return 0;
}