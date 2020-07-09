#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// void print_vector (vector <int> &x){
//     for(int i=0;i<x.size();i++){
//         cout<<x[i]<<" ";
//     }
//     cout<<endl;
// }

void print_grid(vector <string> &t){
    for(int i=0;i<t.size();i++){
        cout<<t[i]<<endl;
    }
    cout<<endl;
}

void update_ans(vector <string> &ans, string &temp, int A, int open_brackets, int close_brackets){
	int i,j,k;
	//cout<<temp<<" ob:"<<open_brackets<<" cb:"<<close_brackets<<endl;
	if(open_brackets==A && close_brackets<open_brackets){
		for(i=close_brackets+1;i<=open_brackets;i++){
			temp.push_back(')');
		}
		ans.push_back(temp);
		for(i=close_brackets+1;i<=open_brackets;i++){
			temp.erase(temp.end()-1);
		}
		return;
	}
	else if(open_brackets<A){
		temp.push_back('(');
		update_ans(ans,temp,A,open_brackets+1,close_brackets);
		temp.erase(temp.end()-1);
		if(close_brackets<open_brackets){
			temp.push_back(')');
			update_ans(ans,temp,A,open_brackets,close_brackets+1);
			temp.erase(temp.end()-1);
		}
	}
	return;
}



vector <string> generateParenthesis(int A) {
	vector <string> ans;
	string temp;
	update_ans(ans,temp,A,0,0);
	return ans;
}

int main(){
	int A=3;
	vector <string> ans=generateParenthesis(A);
	print_grid(ans);
	return 0;
}
