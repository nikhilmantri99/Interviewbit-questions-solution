#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Given an absolute path for a file (Unix-style), simplify it. 
// Note that absolute path always begin with ‘/’ ( root directory ),
// a dot in path represent current directory and double dot represents parent directory.

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

bool is_file_char(char x){
	if(x!='/' && x!=' ' && x!='.' && x!=' '){
		return true;
	}
	else{
		return false;
	}
}

string simplifyPath(string A) {
	stack <string> directories;
	int i=0,j,k;
	while(i<A.size()){
		cout<<A[i]<<endl;
		if(A[i]==' ') break;
		else if(A[i]=='/'){
			i++;
			continue;
		}
		else if(A[i]=='.'){
			if(i+1<A.size()){
				if(A[i+1]=='.'){
					if(directories.empty()==false){
						directories.pop();
					}
					i++;
				}
			}
			i++;
			continue;
		}
		else{
			if(is_file_char(A[i])==true){
				string temp;
				while(is_file_char(A[i])==true && i<A.size()){
					temp.push_back(A[i]);
					i++;
				}
				directories.push(temp);
				temp.clear();
				continue;
			}
		}
	}
	stack <string> d;
	while(directories.empty()==false){
		d.push(directories.top());
		directories.pop();
	}
	string construct;
	//Note that + operator is very inefficient in C++. Try to use append instead

	while(d.empty()==false){
		string temp="/";
		temp.append(d.top());
		construct.append(temp);
		d.pop();
	}
	if(construct.size()==0) construct="/";
	return construct;
}



int main(){
	string unix_path="/a/./b/../../c/";
	cout<<unix_path<<endl;
	cout<<simplifyPath(unix_path)<<endl;
	return 0;
}
