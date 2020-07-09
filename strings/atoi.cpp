#include <bits/stdc++.h>
using namespace std;

bool isnumeric(const string &A,int i){
	if(A[i]-'0'>9 || A[i]-'0'<0){
		return false;
	}
	else{
		return true;
	}
}

int atoi(const string A) {
	int i=0,j,k,sign=1;
	while(i<A.size() && A[i]==' '){
		i++;
	}
	if(i==A.size()) return 0;
	cout<<"i:"<<i<<endl;
	if(A[i]=='-') {
		sign=-1;
		i++;
	}
	else if(A[i]=='+') {
		i++;
	}
	if(isnumeric(A,i)==false){
		return 0;
	}
	vector <int> ans;
	for(;i<A.size() && isnumeric(A,i)==true;i++){
		cout<<"here: "<<A[i]<<endl;
		ans.push_back((int)(A[i]-'0'));
		if(ans.size()>10) {
			if(sign==1){
				return INT_MAX;
			}
			else{
				return INT_MIN;
			}
		}
	}
	for(k=0;k<ans.size();k++){
		cout<<"ans["<<k<<"]: "<<ans[k]<<endl;
	}
	long int x=0;
	for(i=0;i<ans.size();i++){
		x=10*x+ans[i];
	}
	cout<<"x: "<<x<<endl;
	if(x>INT_MAX) {
			if(sign==1){
				return INT_MAX;
			}
			else{
				return INT_MIN;
			}
	}
	return (int)(sign*x);
}

int main(){
	string A="+7";
	cout<<atoi(A)<<endl;
	return 0;
}