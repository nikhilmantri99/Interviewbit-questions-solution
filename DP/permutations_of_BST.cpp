#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long int M=(int)(pow(10,9)+0.5)+7;

void print_matrix(vector <vector <long long int>> &x){
	int i,j;
	for(i=0;i<x.size();i++){
		cout<<"nodes: "<<i<<endl;
		for(j=0;j<x[0].size();j++){
			cout<<"height:"<<j<<" number of BSTs:"<<x[i][j]<<endl;
		}
	}
}

int cntPermBST(int A, int B) {
	int n=A;
	vector<vector<long long int>> C(n+1,vector <long long int> (n+1,0));
    int i, j; 
    // Caculate value of Binomial Coefficient 
    // in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, n); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = ((C[i - 1][j - 1]%M) + C[i - 1][j]%M)%M; 
        } 
    }  
	vector<vector<long long int>> DP(A+1,vector <long long int> (A+1,0));
	int k,l;
	DP[0][0]=1;
	DP[1][0]=1;
	for(i=2;i<=A;i++){//i total nodes in consideration, building upto A nodes
		cout<<"i: "<<i<<endl;
		for(j=1;j<=i;j++){//j is current root
			cout<<"j: "<<j<<endl;
			int left=j-1;
			int right=i-j;
			cout<<"left: "<<left<<"right: "<<right<<endl;
			for(k=0;k<DP[0].size();k++){
				for(l=0;l<DP[0].size();l++){
					if(DP[left][k]!=0 && DP[right][l]!=0){
						int height=1+max(k,l);
						long long int num=((((C[k+l][k]%M)*(DP[left][k]%M))%M)*(DP[right][l]%M))%M;
						cout<<"num:"<<num<<endl;
						DP[i][height]=((DP[i][height]%M)+(num%M))%M;
					}
				}
			}
		}
	}
	print_matrix(DP);
	return (int)DP[A][B]; 
}

int main(){
	int A;
	int B;
	cin>>A>>B;
	cout<<cntPermBST(A,B)<<endl;
	return 0;
}