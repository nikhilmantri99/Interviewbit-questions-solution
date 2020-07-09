#include <stdio.h>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int square_root(int A){
	int start=0,end=46340,mid;
	while(start<=end){
		mid=(start+end)/2;
		cout<<mid<<endl;
		if(mid*mid == A){
			return mid;
		}
		else if(mid*mid<A){
			start=mid+1;
		}
		else if(mid*mid>A){
			end=mid-1;
		}
	}
	if(mid*mid<A){
		while(mid*mid<A){
			mid++;
		}
		return mid-1;
	}
	if(mid*mid>A){
		while(mid*mid>A){
			mid--;
		}
		return mid;
	}
}

int main(){
	int n;
	cin>>n;
	cout<<square_root(n)<<endl;
	return 0;
}