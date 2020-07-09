#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	if(x.size()==0){
		cout<<endl;
		return;
	}
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void update_answer(vector <string> &ans,string &temp, string &A, vector <string> themaps, int index){
	if(index>=A.size()){
		ans.push_back(temp);
		return;
	}
	else{
		int num=A[index]-'0';
		for(int 	i=0;i<themaps[num].size();i++){
			temp.push_back(themaps[num][i]);
			update_answer(ans,temp,A,themaps,index+1);
			temp.erase(temp.end()-1);
		}
	}
	return;
}

vector <string> letterCombinations(string A) {
	vector <string> ans;
	if(A.size()==0) return ans;
	vector <string> themaps;
	themaps.push_back("0");
	themaps.push_back("1");
	themaps.push_back("abc");
	themaps.push_back("def");
	themaps.push_back("ghi");
	themaps.push_back("jkl");
	themaps.push_back("mno");
	themaps.push_back("pqrs");
	themaps.push_back("tuv");
	themaps.push_back("wxyz");
	string temp;
	update_answer(ans,temp,A,themaps,0);
	return ans;
}

int main(){
	string A="23";
	vector <string> ans=letterCombinations(A);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}