#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string countAndSay(int A) {
	string prev="1";
	if(A==1) return prev;
	int i,j,k;
	string current;
	char c;
	int count;
	for(i=2;i<=A;i++){
		//cout<<"prev: "<<prev<<endl;
		current.clear();
		c=prev[0];
		count=0;
		for(j=0;j<prev.size();j++){
			//cout<<"c:"<<c<<" count: "<<count<<endl;
			if(prev[j]==c){
				count++;
			}
			else{
				j=j-1;
				current=current+to_string(count);
				current=current+c;
				c=prev[j+1];
				count=0;
			}
		}
		current=current+to_string(count);
		current=current+c;
		c=prev[j+1];
		count=0;
		//cout<<"current: "<<current<<endl;
		prev.clear();
		prev=prev+current;
	}
	return current;
}

int main(){
	int n;
	cin>>n;
	cout<<countAndSay(n)<<endl;
	return 0;
}