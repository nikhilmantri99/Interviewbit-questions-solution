#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string A) {
	int i,j;
	i=0;
	int max_length=0;
	while(i<A.size()){
		unordered_map <char,int> umap;
		j=i;
		while(j<=A.size()){
			cout<<"j: "<<j<<endl;
			if(j==A.size()){
				max_length=max(j-i,max_length);
				return max_length;
			}
			else if(umap.find(A[j])==umap.end()){
				umap[A[j]]=j;
				j++;
			}
			else{
				max_length=max(j-i,max_length);
				i=umap[A[j]]+1;
				break;
			}
		}
	}
	return max_length;
}

int main(){
	string A="bbbb";
	cout<<lengthOfLongestSubstring(A)<<endl;
	return 0;
}
