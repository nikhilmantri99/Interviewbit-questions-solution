#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void print_vec(vector <int> &x){
	for (int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

bool comparefunc(int &a, int &b){
	string x=to_string(a);
	x.append(to_string(b));
	string y=to_string(b);
	y.append(to_string(a));
	if(x<=y){
		//cout<<x<<" "<<"is less than"<<" "<<y<<endl; 
		return true; 
	}
	else{
		//cout<<x<<" "<<"is greater than"<<" "<<y<<endl;
		return false;
	}
}

int main(){
	vector <int> A={3, 30, 34, 5, 9};
	sort(A.begin(),A.end(),comparefunc);
	string x;
	for(int i=A.size()-1;i>=0;i--){
		x.append(to_string(A[i]));
	}
	cout<<x<<endl;
	return 0;
}