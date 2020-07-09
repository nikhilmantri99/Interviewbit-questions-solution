#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int title_number(string A){
	int Y='A';
	int sum=0;
	for(int i=0;i<A.size();i++){
		int X=A[A.size()-1-i];
		sum+=pow(26,i)*(X-Y+1);
	}
	return sum;
}

int main(){
	string t;
	cin>>t;
	cout<<title_number(t);
	return 0;
}