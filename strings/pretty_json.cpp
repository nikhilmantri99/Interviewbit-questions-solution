#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector <string> prettyJSON(string A) {
	vector <string> ans;
	int tabs=0;
	string temp;
	int j,k;
	for(int i=0;i<A.size();i++){
		cout<<i<<" "<<A[i]<<endl;
		if(A[i]=='{' || A[i]=='['){
			int count=0;
			for(j=0;j<temp.size();j++){
				if(temp[j]!='\t'){
					count++;
				}
			}
			if(count>0){
				ans.push_back(temp);
			}
			temp.clear();
			for(j=0;j<tabs;j++){
				temp.push_back('\t');
			}
			tabs++;
			temp.push_back(A[i]);
			ans.push_back(temp);
			temp.clear();
			for(j=0;j<tabs;j++){
				temp.push_back('\t');
			}
		}
		else if(A[i]=='}'||A[i]==']'){
			int count=0;
			for(j=0;j<temp.size();j++){
				if(temp[j]!='\t'){
					count++;
					break;
				}
			}
			if(count>0){
				ans.push_back(temp);
			}
			temp.clear();
			tabs--;
			for(j=0;j<tabs;j++){
				temp.push_back('\t');
			}
			temp.push_back(A[i]);
			ans.push_back(temp);
			temp.clear();
			for(j=0;j<tabs;j++){
				temp.push_back('\t');
			}	
		}
		else if(A[i]==','){
			temp.push_back(A[i]);
			ans.push_back(temp);
			temp.clear();
			for(j=0;j<tabs;j++){
				temp.push_back('\t');
			}
		}
		else if(A[i]==' '){
			continue;
		}
		else{
			temp.push_back(A[i]);
		}
	}
	return ans;
}

int main(){
	string X="{'id':100,'firstName':'Jack','lastName':'Jones','age':12}";
	string Y="{";
	vector <string> ans= prettyJSON(Y) ;
	int i;
	for(i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}