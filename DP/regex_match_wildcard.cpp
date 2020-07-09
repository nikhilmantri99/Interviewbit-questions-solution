#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool ismatch(const string &A /*text*/, const string &B/*pattern*/){
	int i,j,k;
	vector <vector<bool>> T(A.size()+1,vector <bool> (B.size()+1));
	T[0][0]=true;
	for(i=1;i<T.size();i++){
		T[i][0]=false;
	}
	for(j=1;j<T[0].size();j++){
		T[0][j]=false;
		if(j>=1 && B[j-1]=='*'){
			T[0][j]=T[0][j-1];
		}
	}
	for(i=1;i<A.size()+1;i++){
		for(j=1;j<B.size()+1;j++){
			if(A[i-1]==B[j-1] || B[j-1]=='?'){
				T[i][j]=T[i-1][j-1];
			}
			else if(B[j-1]=='*'){
                T[i][j]=T[i][j-1]||T[i-1][j];
			}
			else{
				T[i][j]=false;
			}
		}
	}
	return T[A.size()][B.size()];
}

int isMatch(const string A, const string B) {
    bool truth=ismatch(A,B);
	if(truth==true){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	string A="";
	string B="";
	cout<<isMatch(A,B)<<endl;
	return 0;
}