#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long fact(int n){
	if(n<0){
		return 0;
	}
	if(n>=0 && n<=1){
		return 1;
	}
	if(n>12){
		return INT_MAX;
	}
	long long int ans=1;
	int i=1;
	for(i=1;i<=n;i++){
		ans=ans*i;
	}
	return ans;
}

void update_ans(int k,int n,vector <bool> &check, string &ans){
	//cout<<"ans:"<<ans<<endl;
	if(ans.size()<10){
		//cout<<"top ans:"<<ans<<endl;
	}
	long long int num=0;
	int i,j;
	if(k==0){
		i=check.size()-1;
		while(i>=0){
			if(check[i]==true){
				check[i]=false;
				string t=to_string(i);
				ans.append(t);
			}
			i--;
		}
		return;
	}
	i=0;
	while(check[i]==false && i<check.size()){
		i++;
	}
	if(i==n+1){
		return;
	}
	int count=0;
	for(j=1;j<check.size();j++){
		if(check[j]==false){
			count++;
		}
	}
	long long int x=fact(n-count-1);
	if(ans.size()<10){
		//cout<<"fact:"<<x<<endl;
	}
	while(num+x<(long long int)k && i<check.size()){
		if(check[i]==false){
			i++;
		}
		else{
			num=num+x;
			if(num!=0){
				//cout<<"num: "<<num<<endl;
			}
			i++;
			while(check[i]==false && i<check.size()){
				i++;
			}
		}
	}
	// if(i<11){
	// 	cout<<"ans:"<<ans<<endl;
	// 	cout<<"i:"<<i<<endl;
	// }
	if(num+x==k){
		num=num+x;
		check[i]=false;
		string t=to_string(i);
		ans.append(t);
		update_ans(k-num,n,check,ans);
		return;
	}
	else{
		check[i]=false;
		string t=to_string(i);
		ans.append(t);
		update_ans(k-num,n,check,ans);
		return;
	}
}

string getPermutation(int A, int B) {
	int n=A;
	int k=B;
	string ans;
	if(k==0||n==0||k>fact(n)){
	    return ans; 
	}
	vector <bool> check(n+1,true);
	check[0]=false;
	ans.clear();
	update_ans(k,n,check,ans);
	return ans;
}

int main(){
	int i,j;//n,k
	for(i=10;i<=15;i++){
		for(j=0;j<=INT_MAX;j++){
			cout<<"n: "<<i<<" k: "<<j<<endl;
			cout<<getPermutation(i,j)<<endl;
		}
	}
	// int n=10,k=23	;
	// cout<<getPermutation(n,k)<<endl;
	return 0;
}
