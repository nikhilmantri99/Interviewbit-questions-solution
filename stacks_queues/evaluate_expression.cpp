#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void PrintStack(stack<string> s) 
{ 
    if (s.empty())  
        return; 
    string x = s.top();  
    s.pop(); 
    PrintStack(s);  
    cout << x << " "; 
    s.push(x); 
} 
void printstack(stack <string> &s){
	cout<<"contents of stack: (Bottom to top):"<<endl;
	PrintStack(s);
	cout<<endl;
}


bool isoperation(string &a){
	if(a=="+" || a=="-"||a=="*"||a=="/"){
		return true;
	}
	else{
		return false;
	}
}

int evaluate(int left, int right, string &sign){
	if (sign=="+") return left +right;
	if (sign=="-") return left-right;
	if (sign=="/") return left/right;
	if (sign=="*") return left*right;
	return 0;
}

int string_to_int(string &s){
    int x=0,i=0,sign=1;
    if(s[0]=='-'){
    	sign=-1;
    	i=1;
    }
    for(;i<s.size();i++){
        x=10*x+(int)(s[i]-'0');
    }
    return sign*x;
}


void sort_the_stack(stack <string> &s){
	printstack(s);
	if(s.empty()==true){
		return;
	}
	if(isoperation(s.top())==false){
		int left=string_to_int(s.top());
		s.pop();
		if(s.empty()==true){
			s.push(to_string(left));
			return;
		}
		if(isoperation(s.top())==false){
			int right=string_to_int(s.top());
			s.pop();
			string sign=s.top();
			s.pop();
			int temp=evaluate(left,right,sign);
			s.push(to_string(temp));
			sort_the_stack(s);
		}
		else{
			s.push(to_string(left));
			return;
		}
	}
	else{
		return;
	}
}

int evalRPN(vector<string> &A) {
	if(A.size()==0){
        return 0;
    }
    if(A.size()==1){
        return string_to_int(A[0]);
    }
	stack <string> s;
	for(int i=A.size()-1;i>=0;i--){
		cout<<"here"<<endl;
		if(s.empty()==true){
			s.push(A[i]);
		}
		else{
			if(isoperation(s.top())==false && isoperation(A[i])==false){
				s.push(A[i]);
				sort_the_stack(s);
			}
			else{
				s.push(A[i]);
			}
		}
		sort_the_stack(s);		
	}
	//cout<<s.top()<<endl;
	return string_to_int(s.top());
}

int main(){
	vector <string> A={"4", "13", "5", "/", "+"};
	cout<<evalRPN(A)<<endl;
	return 0;
}
