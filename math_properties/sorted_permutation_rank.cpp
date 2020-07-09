#include <bits/stdc++.h>
using namespace std;

#define M 1000003

int factorial(int n){
	if(n==0||n==1){
		return 1;
	}
	else{
		return ((n%M)*(factorial(n-1)%M))%M;
	}
}

int relu(int x){
	return max(0,x);
}

int findRank(string A) {
	vector <int> alpha(26,0);
	int n=A.size();
	int i,j,k,sum=0;
	for(i=0;i<A.size();i++){
		alpha[(int)A[i]-'a']++;
	}
	for(i=0;i<alpha.size();i++){
		sum+=alpha[i];
		if(alpha[i]!=0){
			alpha[i]=sum;
		}
	}
	//cout<<endl;	
	sum=0;
	for(i=0;i<A.size();i++){
		n--;
		//cout<<"n: "<<n<<" "<<"factorial(n): "<<factorial(n)<<" relu(alpha[(int)A[i]-'a']-1): "<<relu(alpha[(int)A[i]-'a']-1)<<endl;
		sum+=(factorial(n)*relu(alpha[(int)A[i]-'a']-1))%M;
		sum=sum%M;
		for(j=A[i]-'a';j<alpha.size();j++){
			if(alpha[j]>0) alpha[j]--;
		}
		//cout<<"Resetting: ";
	}	
	return (sum+1)%M;
}

int main(){
	string s;
	cin>>s;
	cout<<findRank(s)<<endl;
	return 0;
}