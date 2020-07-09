#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string solve(string A) {
	int i,j,k;
	string temp;
	string ans;
	i=0;
	j=A.size();
	while(i<A.size() && A[i]==' '){
		i++;
	}
	while(j>=0 && A[j]==' '){
		j--;
	}
	for(;i<=j;i++){
		if(A[i]==' '){
			while(i<=j && A[i]==' '){
				i++;
			}
			i=i-1;
			ans=temp+ans;
			temp.clear();
			ans=' '+ans;
			cout<<"ans:"<<ans<<endl;
		}
		else{
			temp=temp+A[i];	
		}
	}
	while(ans.size()>=1 && ans[0]==' ') ans.erase(0,1);
    //for(k=0;k<ans.size();k++) cout<<k<<": "<<ans[k]<<endl;
    while(temp.size()>=1 && temp[temp.size()-1]==' ') temp.erase(temp.size()-1,1);
    //for(k=0;k<temp.size();k++) cout<<k<<": "<<temp[k]<<endl;
    if(ans.size()==0) {
    	ans.clear();
    	ans=temp+ans;
    	ans.erase(ans.size()-1,1);
    	cout<<"if"<<endl;
    }
    else{
    	cout<<"else"<<endl;
    	ans=temp+ans;	
    } 
	//ans=temp+ans;
	cout<<A.size()<<" "<<ans.size()<<endl;
	for(k=0;k<ans.size();k++) cout<<k<<": "<<ans[k]<<endl;
	return ans;
}

int main(){
	string t="joker fucks you" ;
	cout<<solve(t)<<endl;
	return 0;
}