#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int comparestringnums(string s1,string s2){
	//return 1 if s1>s2 else return -1 else return 0 if same
	if (s1.size()>s2.size()) return 1;
	else if (s2.size()>s1.size()) return -1;
	else{
		int n=s1.size();
		int i;
		for(i=0;i<n;i++){
			int num1=s1[i]-'0';
			int num2=s2[i]-'0';
			if(num1>num2){
				return 1;
			}
			else if(num2>num1){
				return -1;
			}
			else{
				continue;
			}
		}
		return 0;
	}
}

int compareVersion(string A, string B) {
	int n1=A.size();
	int n2=B.size();
	int i,j,k;
	string temp1;
	string temp2;
	
	i=0;
	j=0;
	k=0;
	while(i<n1||j<n2){
		temp1.clear();
		temp2.clear();
		while(A[i]!='.' && i<n1){
			temp1+=A[i];
			//cout<<temp1<<endl;
			i++;
		}
		while(B[j]!='.' && j<n2){
			temp2+=B[j];
			//cout<<temp2<<endl;
			j++;
		}
		//cout<<"temp1: "<<temp1<<" temp2: "<<temp2<<endl;
		int result=comparestringnums(temp1,temp2);
		if(result==0){
			i++;
			j++;
			continue;
		}
		else{
			return result;
		}
	}
	return 0;
}

int main(){
	string s1="1.13";
	string s2="1.13.4";
	//cin>>s1>>s2;
	cout<<compareVersion(s1,s2)<<endl;
	return 0;	
}
