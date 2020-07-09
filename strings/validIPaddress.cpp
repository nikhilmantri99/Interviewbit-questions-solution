#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool check_validity(string &x){
	if(x.size()==0){
		return false;
	}
	if(x.size()>1){
		if(x[0]=='0'){
			return false;
		}
	}
	int t=stoi(x);
	if(t>=0 && t<=255){
		return true;
	}
	else{
		return false;
	}
}

vector <string> restoreIpAddresses(string A) {
	vector <string> ans;
	if(A.size()<4 || A.size()>12){
		return ans;
	}
	string p1,p2,p3,p4;
	int n=A.size(),i,j,k,rem;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			for(k=1;k<=3;k++){
				rem=n-(i+j+k);
				if(rem<=0||rem>3){
					continue;
				}
				else{
					cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" rem:"<<rem<<endl;
					p1.clear();
					p2.clear();
					p3.clear();
					p4.clear();
					p1=A.substr(0,i);
					p2=A.substr(i,j);
					p3=A.substr(i+j,k);
					p4=A.substr(i+j+k,rem);
					cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
					int count=0;
					bool val=check_validity(p1);
					if(val==true){
						count++;
					}
					val=check_validity(p2);
					if(val==true){
						count++;
					}
					val=check_validity(p3);
					if(val==true){
						count++;
					}
					val=check_validity(p4);
					if(val==true){
						count++;
					}
					if(count==4){
						string temp=p1+"."+p2+"."+p3+"."+p4;
						ans.push_back(temp);
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	string X="25525511135";
	vector <string> ans=restoreIpAddresses(X);
	int i;
	cout<<"Thus the following are the valid IP addresses:"<<endl;
	for(i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}