#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int max4(int a,int b,int c,int d){
	return max(max(a,b),max(c,d));
}

int max3(int a,int b,int c){
	return max(max(a,b),c);
}

void print_matrix(vector<vector<int>> &A){
    int i,j;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int manhattan_distance(int i,int j,int root_i,int root_j){
	cout<<"root_j:"<<root_j<<" root_i:"<<root_i<<" i:"<<i<<" j:"<<j<<endl;
	int dist=abs(root_j-j)+abs(root_i-i);
	cout<<dist<<endl;
	return dist;
}

int return_max(vector<vector<int> > &B,int root_i,int root_j,int i,int j,int K,int add_direction){
	//add_direction = 0 for centre,1 for go up, 2 for down, 3 for left, 4 for right.
	int k,l;
	if(i<0 || i>=B.size() || j<0 || j>=B[0].size()){
		return INT_MIN;
	}
	if(manhattan_distance(i,j,root_i,root_j)>K){
		return INT_MIN;
	}
	int maxval=B[i][j];
	if(add_direction==0||add_direction==1||add_direction==2){
		k=0;
		while(manhattan_distance(i,j+k,root_i,root_j)<=K){
			cout<<"checking at i,j="<<i<<","<<j+k<<endl;
			if(j-k<0 && j+k>=B[0].size()){
				break;
			}
			else if(j-k<0){
				maxval=max(B[i][j+k],maxval);
			}
			else if(j+k>=B[0].size()){
				maxval=max(B[i][j-k],maxval);
			}
			else{
				maxval=max3(maxval,B[i][j+k],B[i][j-k]);
			}
			k++;
		}
		if(add_direction==1||add_direction==0){
			maxval=max(maxval,return_max(B,root_i,root_j,i-1,j,K,1));
		}
		if(add_direction==2||add_direction==0){
			maxval=max(maxval,return_max(B,root_i,root_j,i+1,j,K,2));	
		}
	}
	if(add_direction==3||add_direction==4||add_direction==0){
		k=0;
		while(manhattan_distance(i+k,j,root_i,root_j)<=K){
			cout<<"checking at i,j="<<i+k<<","<<j<<endl;
			if(i-k<0 && i+k>=B.size()){
				break;
			}
			else if(i-k<0){
				maxval=max(B[i+k][j],maxval);
			}
			else if(i+k>=B.size()){
				maxval=max(B[i-k][j],maxval);
			}
			else{
				maxval=max3(maxval,B[i-k][j],B[i+k][j]);
			}
			k++;
		}
		if(add_direction==3||add_direction==0){
			maxval=max(maxval,return_max(B,root_i,root_j,i,j-1,K,3));
		}
		if(add_direction==4||add_direction==0){
			maxval=max(maxval,return_max(B,root_i,root_j,i,j+1,K,4));	
		}
	}
	return maxval;
}

vector <vector<int> > solve(int A, vector<vector<int> > &B) {
	int i,j,K=A;
	print_matrix(B);
	vector <vector <int>> ans(B.size(),vector <int> (B[0].size(),INT_MIN));
	for(i=0;i<ans.size();i++){
		for(j=0;j<ans[0].size();j++){
			ans[i][j]=max(ans[i][j],return_max(B,i,j,i,j,A,0));
		}
	}
	print_matrix(ans);
	return ans;
}

int max_of(int a, int b, int c, int d, int e) {
    return max(max(max(a, b), max(c, d)), e);
}

int main(){
	vector <vector <int>> A={{1,2,4,6,7,18,24,78},{4,5,8,6,7,18,24,78}};
	//cout<<return_max(A,0,0,0,0,2,0)<<endl;
	vector <vector <int>>ans=solve(2,A);
	return 0;
}