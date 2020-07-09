#include <bits/stdc++.h>
using namespace std;

void print_stack( stack <string> x){
	cout<<"stack top to bottom: ";
	while(x.empty()==false){
		cout<<x.top()<<" ";
		x.pop();
	}
	cout<<endl;
}

bool issign(string &x){
    if(x=="+"||x=="-"||x=="*"||x=="/"){
        return true;
    }
    return false;
}

int evaluate(int x, int y, string &sign){
	if(sign=="+"){
		return x+y;
	}
	if(sign=="-"){
		return x-y;
	}
	if(sign=="*"){
		return x*y;
	}
	if(sign=="/"){
		return (x/y);
	}
	return 0;
}

int toint(string &x){
	int ans=0;
	for(int i=0;i<x.size();i++){
		ans=10*ans+(int)(x[i]-'0');
	}
	return ans;
}

void check_stack(stack <string> &s){
	if(s.empty()){
		return;
	}
	print_stack(s);
	if(issign(s.top())){
		return;
	}
	string x=s.top();
	s.pop();
	if(s.empty() || issign(s.top())){
		s.push(x);
		return;
	}
	string y=s.top();
	s.pop();
	if(s.empty()){
		s.push(y);
		s.push(x);
		return;
	}
	int p=toint(x);
	int q=toint(y);
	int ans=evaluate(p,q,s.top());
	s.pop();
	s.push(to_string(ans));
	check_stack(s);
}

int evalRPN(vector<string> &A) {
	if(A.size()==0){
		return 0;
	}
	if(A.size()==1){
		return toint(A[0]);
	}
	stack <string> s;
	int i,j,k;
	reverse(A.begin(),A.end());
	for(i=0;i<A.size();i++){
		//cout<<"i:"<<i<<" "<<A[i]<<endl;
		if(s.empty()){
			s.push(A[i]);
		}
		else if(issign(A[i])==false && issign(s.top())==false){
			//print_stack(s);
			s.push(A[i]);
			check_stack(s);
			print_stack(s);
		}
		else{
			s.push(A[i]);
		}
	}
	return toint(s.top());
}

int main(){
	vector <string> A={"5", "1", "2", "+", "4", "*", "+", "3", "-"};
	cout<<evalRPN(A)<<endl;
	return 0;
}

