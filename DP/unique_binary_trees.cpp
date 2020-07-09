#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//think recursively in terms of number of nodes in left and right sub_trees;

int num_trees_recursive(int num_nodes){
	if(num_nodes<=0){
		return 1;
	}
	if(num_nodes==1){
		return 1;
	}
	if(num_nodes==2){
		return 2;
	}
	int i;
	int sum=0;
	for(i=1;i<=num_nodes;i++){
		sum=sum+num_trees_recursive(i-1)*num_trees_recursive(num_nodes-i);
	}
	return sum;
}

int numTrees(int A) {
	vector <int> dp(A+1,0);
	int i,j;
	dp[0]=1;
	for(i=1;i<=A;i++){
		for(j=1;j<=i;j++){
			dp[i]=dp[i]+dp[j-1]*dp[i-j];
		}
	}
	return dp[A];
}

int main(){
	int A;
	cin>>A;
	cout<<numTrees(A)<<endl;
	return 0;
}