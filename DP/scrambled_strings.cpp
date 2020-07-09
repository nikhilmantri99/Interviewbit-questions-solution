#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void increment(unordered_map <char,int> &m,const char &x){
	if(m.find(x)==m.end()){
		m[x]==1;
	}
	else{
		m[x]++;
	}
}

void decrement(unordered_map <char,int> &m,const char &x){
	m[x]--;
	if(m[x]==0){
		m.erase(x);
	}
}

bool is_anagram(const string &A, const string &B){
	unordered_map <char,int> mapA,mapB;
	for(int i=0;i<A.size();i++){
		increment(mapA,A[i]);
		increment(mapB,B[i]);
	}
	if(mapB==mapA){
		return true;
	}
	return false;
}

bool is_scrambled(string A,string B){
	cout<<A<<" "<<B<<endl;
	if(A.size()==0){
		return true;
	}
	if(A.size()==1){
		if(A[0]==B[0]){
			return true;
		}
		else{
			return false;
		}
	}
	if(A.size()==2){
		if(A[0]==B[0] && A[1]==B[1]){
			return true;
		}
		else if(A[1]==B[0] && A[0]==B[1]){
			return true;
		}
		else{
			return false;
		}
	}
	//int i,j,k;
	unordered_map <char,int> mapA,mapB,mapC;
	increment(mapA,A[0]);
	increment(mapB,B[0]);
	increment(mapC,B[B.size()-1]);

	int i=1,j=1,k=A.size()-2;
	while(i<A.size() && j<B.size() && k>=0){
		bool truth;
		if(mapA==mapB){
			cout<<"here1"<<endl;
			truth=is_scrambled(A.substr(0,i),B.substr(0,i)) && is_scrambled(A.substr(i),B.substr(i));
			if(truth==true){
				return true;
			}
		}
		if(mapA==mapC){
			cout<<"here2"<<endl;
			truth=is_scrambled(A.substr(0,i),B.substr(k+1)) && is_scrambled(A.substr(i),B.substr(0,k+1));
			if(truth==true){
				return true;
			} 
		}
		if(i<A.size() && j<B.size() && k>=0){
			increment(mapA,A[i]);
			increment(mapB,B[i]);
			increment(mapC,B[k]);
		}
		i++;
		j++;
		k--;
	}
	return false;
}

int isScramble(const string A, const string B) {
    if(A.size()!=B.size()){
    	return 0;
    }
    bool truth;
    truth=is_anagram(A,B);
    if(truth==false){
    	return 0;
    }
    cout<<"here"<<endl;
    truth=is_scrambled(A.substr(0),B.substr(0));
    if(truth==true){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
	string A="phqtrnilf";
	string B="ilthnqrpf";
	cout<<isScramble(A,B)<<endl;
	return 0;
}