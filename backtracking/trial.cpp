#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isnum(char x){
	if((int)(x-'0')>=0 && (int)(x-'0')<=9){
		return true;
	}
	return false;
}

int main(){
	int n=3;
	vector <string> temp(n,string(n,'.'));
	for(int i=0;i<n;i++){
		cout<<temp[i]<<endl;
	}
	return 0;
}