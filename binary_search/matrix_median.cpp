#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &A) {
	int mini=INT_MAX,maxi=INT_MIN,i,j,k;
	for(i=0;i<A.size();i++){
		if(A[i][0]<mini){
			mini=A[i][0];
		}
		if(A[i][A[0].size()-1]>maxi){
			maxi=A[i][A[0].size()-1];
		}
	}
	//cout<<mini<<" "<<maxi<<endl;
	int mid,place=0,desired=A.size()*A[0].size()/2+1;
	while(mini<maxi)
	{
		place=0;
		mid=mini+(maxi-mini)/2;
		//cout<<mid<<endl;
		for(i=0;i<A.size();i++){
			place+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
		}
		if(place<desired){
			mini=mid+1;
		}
		else{
			maxi=mid;
		}
	}
	return mini;
}

int main(){
	vector <vector<int>> A={{1,3,5},{2,4,6},{3,5,7}};
	cout<<findMedian(A)<<endl;
	return 0;
}