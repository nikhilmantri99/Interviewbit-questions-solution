#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void PrintStack(stack <int> s) 
{ 
    if (s.empty())  
        return; 
    int x = s.top();  
    s.pop(); 
    PrintStack(s);  
    cout << x << " "; 
    s.push(x); 
} 
void printstack(stack <int> &s){
	cout<<"contents of stack: (Bottom to top):"<<endl;
	PrintStack(s);
	cout<<endl;
}

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

//return 1 if redundant braces present else return 0
int braces(string A){
    stack <char> s;
    for(int i=0;i<A.size();i++){
    	if(s.empty()==true){
    		s.push(A[i]);
    	}
    	else if(A[i]==')'){
    		if(s.top()=='(') return 1;
    		else{
    			int flag=0;
    			while(s.top()!='('){
    				if(s.top()=='+' || s.top()=='-' || s.top()=='*'|| s.top()=='/'){
    					flag++;
    				}
    				s.pop();
    			}
    			if(flag==0){
    					return 1;
    			}
    			s.pop();
    		}
    	}
    	else{
    		s.push(A[i]);
    	}
    }
    return 0;
}


int main(){
	string A= "(a+(b)/c)";
	cout<<braces(A)<<endl;
	return 0;
}