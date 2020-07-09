#include <bits/stdc++.h> 
using namespace std;

void return_index(int start,int end,const vector<int> &A, int B,int &mini,int &maxi){
	int mid;
	while(start<=end){
		mid=start+(end-start)/2;
		if(A[mid]==B){
			//cout<<"found at: "<<mid<<endl;
			if(mid<mini){
				mini=mid;
				return_index(0,mid-1,A,B,mini,maxi);
			}
			if(mid>maxi){
				maxi=mid;
				return_index(mid+1,A.size()-1,A,B,mini,maxi);
			}
			break;
		}
		else if(A[mid]<B){
			start=mid+1;
		}
		else if(A[mid]>B){
			end=mid-1;
		}
	}
	return;
}

vector <int> searchRange(const vector<int> &A, int B) {
	int mini=INT_MAX,maxi=INT_MIN;
	return_index(0,A.size()-1,A,B,mini,maxi);
	if(mini==INT_MAX && maxi==INT_MIN){
		vector <int> temp={-1,-1};
		return temp;
	}
	else{
		vector <int> temp;
		temp.push_back(mini);
		temp.push_back(maxi);
		return temp;
	}
}

int main(){
	cout<<"Enter the value to be searched:"<<endl;
	int B;
	cin>>B;
	cout<<"Enter the number of elements"<<endl;
	int n;
	cin>>n;
	vector <int> A;
	int i;
	for(i=0;i<n;i++){
		int temp;
		cin>>temp;
		A.push_back(temp);
	}
	vector <int> ans=searchRange(A,B);
	cout<<"Ans: "<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}