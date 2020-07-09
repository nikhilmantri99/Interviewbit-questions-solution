#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int A=34;
	int temp=A>>1;
	cout<<A<<" "<<temp<<endl;
	return 0;
}