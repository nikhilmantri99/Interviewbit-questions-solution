#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vec(vector <int> &A){
	for(int i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

int binary_search(vector <int> &A, int left, int right, int val){
	if(left==right){
	    return left;
	}
	if(val<=A[left]){
		return left;
	}
	while(left<=right){
		int mid=left+(right-left)/2;
		if(mid==(A.size()-1) && A[mid]<=val){
			return mid;
		}
		else if(A[mid]<=val && A[mid+1]>=val){
			if(abs(A[mid]-val)<=abs(A[mid+1]-val)){
				return mid;
			}
			else{
				return mid+1;
			}
		}
		else if(A[mid]<val){
			left=mid+1;
		}
		else if(A[mid]>val){
			right=mid-1;
		}
	}
	return -1;
}

int threeSumClosest(vector<int> &A, int B) {
    int i,j,k;
    long long int sum=INT_MAX;
    sort(A.begin(),A.end());
    //print_vec(A);
    //cout<<"target:"<<B<<endl;
    for(i=0;i<A.size()-2;i++){
        for(j=i+1;j<A.size()-1;j++){
            
            int temp=B-(A[i]+A[j]);
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            //cout<<"temp:"<<temp<<endl;
            int index=binary_search(A,j+1,A.size()-1,temp);
            //cout<<"index:"<<index<<endl;
            long long int localsum=A[i]+A[j]+A[index];
            // cout<<"localsum:"<<localsum<<" sum:"<<sum<<endl;
            // cout<<abs(localsum-B)<<" "<<abs(sum-B)<<endl;
            if(abs(localsum-B)<=abs(sum-B)){
                //cout<<"inside"<<endl;
                sum=localsum;
            }
        }
    }
    return (int)sum;
}
int main(){
	vector <int> A={-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3};
	int val=-1;
	vector <int> B={-1,2,1,4};
	int val1=1;
	//cout<<B.size()<<endl;
	int sum=threeSumClosest(A,val);
	cout<<sum<<endl;
	return 0;
}