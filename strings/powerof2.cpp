#include <bits/stdc++.h>
using namespace std;

bool isodd(string &A){
	if((A[A.size()-1]-'0')%2==1) return true;
	else return false;
}

string into2(string &A){
    int val,prev=0;
    string twice;
    for(int i=A.size()-1;i>=0;i--){
        val=(A[i]-'0')*2+prev;
        prev=val/10;
        twice=to_string(val%10)+twice;
    }
    if(prev!=0){
    	twice=to_string(prev)+twice;		
    }
    return twice;
}

int power(string A) {
	int i,j,k;
	string prev="1";
	string current;
	while(prev.size()<=A.size()){
		if(prev==A){
			return true;
		}
		current.clear();
		current=into2(prev);
		cout<<"current: "<<current<<endl;
		prev.clear();
		prev=current;
	}
	return false;    
}

string divideby2(string &A){
	string quotient;
	if(A=="1"){
		quotient='0';
		return quotient;
	}
	int rem;
	int prev=0;
	int current;
	int i,j,k;
	for(i=0;i<A.size();i++){
		current=10*prev+((int)(A[i]-'0'));
		//cout<<"current: "<<current<<endl;
		quotient=quotient+to_string((int)current/2);
		//cout<<"quotient: "<<quotient<<endl;
		prev=current%2;
	}
	while(quotient[0]=='0'){
		quotient.erase(0,1);
	}
	return quotient;
}

int power1(string A){
	int i,j,k;
	while(A!="1"){
		if(isodd(A)==true) return 0;
		A=divideby2(A);
		cout<<"quotient:"<<A<<endl;
	}
	return 1;
}

int main(){
	string temp;
	cin>>temp;
	cout<<power1(temp)<<endl;
	return 0;
}
