#include <bits/stdc++.h>
using namespace std;

int avg(int a,int b){
	return (a+b)/2;
}

int median_of_2_arrays(vector <int> &x, vector <int> &y){
	int small=x.size(),large=y.size();
	int partition=(small+large+1)/2;
	int total=x.size()+y.size();
	int median,start=0,found=0,end=small,mid;
	while(start<=end){
		mid=(start+end)/2;
		cout<<"mid:"<<mid<<" partition-mid-2:"<<partition-mid-2<<endl;
		if(mid<x.size() && (partition-mid-2)>=0 && x[mid]<=y[partition-mid-1] && y[partition-mid-2]<=x[mid+1]){
			found++;
			break;
		}
		else if(x[mid]<y[partition-mid-1]){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
	}
	if(found==1){
		if(total%2==1) median=max(x[mid],y[partition-mid-2]);
		else{
		median=avg(max(x[mid],y[partition-mid-2]),min(x[mid+1],y[partition-mid-1]));
		}
	}
	else{
		if(x[0]>=y[large-1]){
			return y[partition-1];
		}
		else{
			return y[partition-x.size()-1];
		}
	}
}

int median_naive(vector <int> &x,vector <int> &y){
	vector <int> t;
	int i;
    for(i=0;i<x.size();i++) t.push_back(x[i]);
	for(i=0;i<y.size();i++) t.push_back(y[i]);
	sort(t.begin(),t.end());
	for(i=0;i<t.size();i++) cout<<(t[i])<<" ";
	cout<<endl;
	return t[(t.size()-1)/2];
}

int main(){
	vector <int> A={2,5,8,13,15,23};
	vector <int> B={6,7,9,10,11,12,17,19,20};
	cout<<median_of_2_arrays(A,B)<<endl;
	cout<<"naive: "<<median_naive(A,B)<<endl;
	return 0;
}