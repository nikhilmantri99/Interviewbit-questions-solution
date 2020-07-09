#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

struct node{
	int lower;
	int upper;
};

void update_ans(vector <int> &ans,int A1, int B1, int C1, int D1){
	if(ans.size()==0){
		ans.push_back(A1);
		ans.push_back(B1);
		ans.push_back(C1);
		ans.push_back(D1);
		return;
	}
	else{
		if(ans[0]<A1 || (ans[0]==A1 && ans[1]<B1) || (ans[0]==A1 && ans[1]==B1 && ans[2]<C1) || (ans[0]==A1 && ans[1]==B1 && ans[2]==C1 && ans[3]<D1)){
			return;
		}
		else{
			ans[0]=A1;
			ans[1]=B1;
			ans[2]=C1;
			ans[3]=D1;
			return;
		}
	}
	return;
}

vector <int> equal(vector<int> &A) {
	unordered_map <int,node> umap;
	vector <int> ans;
	node temp;
	for(int i=0;i<A.size();i++){
		for(int j=i+1;j<A.size();j++){
			int sum=A[i]+A[j];
			if(umap.find(sum)==umap.end()){
				temp.lower=i;
				temp.upper=j;
				umap[sum]=temp;
			}
			else{
				if(umap[sum].lower!=i && umap[sum].lower!=j && umap[sum].upper!=i && umap[sum].upper!=j){
					update_ans(ans,umap[sum].lower,umap[sum].upper,i,j);
				}
			}
		}
	}
	return ans;
}

int main(){
	vector <int> A={3, 4, 7, 1, 2, 9, 8};
	vector <int> ans=equal(A);
	print_vector(ans);
	return 0;
}