#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Again, think recursion.
// At every step, you have 2 options :
// 1) Add ‘(‘ to the string.
// 2) Add ‘)’ to the string.
// However, you need to make sure, that the number of closing brackets do not exceed number of opening brackets at any point of time.
// Also, make sure that the number of opening brackets never exceeds n.

void print_vector(vector <string> &x){
	if(x.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<endl;
	}
}

void update_answer(vector <string> &ans, string temp, int required, int open_brackets, int closed_brackets){
	if(open_brackets==required){
		if(closed_brackets==required){
			ans.push_back(temp);
		}
		while(closed_brackets<required){
			temp.push_back(')');
			closed_brackets++;
		}
		ans.push_back(temp);
		return;
	}
	if(open_brackets==closed_brackets){
		temp.push_back('(');
		open_brackets++;
		update_answer(ans,temp,required,open_brackets,closed_brackets);
	}
	else if(open_brackets>closed_brackets){
		temp.push_back('(');
		open_brackets++;
		update_answer(ans,temp,required,open_brackets,closed_brackets);
		temp.erase(temp.end()-1);
		open_brackets--;

		temp.push_back(')');
		closed_brackets++;
		update_answer(ans,temp,required,open_brackets,closed_brackets);
		temp.erase(temp.end()-1);
		closed_brackets--;
	}
}

vector <string> generateParenthesis(int A) {
	vector <string> ans;
	string temp;
	int i;
	int open_brackets=0,closed_brackets=0;
	update_answer(ans,temp,A,open_brackets,closed_brackets);
	return ans;
}


int main(){
	int A;
	cin>>A;
	vector <string> ans=generateParenthesis(A);
	cout<<"final answer:"<<endl;
	print_vector(ans);
	return 0;
}
