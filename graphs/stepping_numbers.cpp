#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_vector (vector <int> &x){
	int i;
	for(i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void generate_numbers(vector <int> &ans,int current_num,int last_digit,int A, int B){
	if(current_num>=A && current_num<=B){
		ans.push_back(current_num);
	}
	if(current_num>B){
		return;
	}
	//important corner cases 0 & 9.
	if(last_digit==0){
		current_num=10*current_num+1;
		generate_numbers(ans,current_num,1,A,B);
	}
	else if(last_digit==9){
	    current_num=10*current_num+8;
		generate_numbers(ans,current_num,8,A,B);
	    
	}
	else{
		int temp=(last_digit-1)%10;
		int copy=current_num;
		current_num=10*current_num+temp;
		generate_numbers(ans,current_num,temp,A,B);
		temp=(last_digit+1)%10;
		copy=10*copy+temp;
		generate_numbers(ans,copy,temp,A,B);
	}
}

vector <int> stepnum(int A, int B) {
	vector <int> ans;
	// important lowelimit=0
	if(A==0){
		ans.push_back(0);
	}
	int i,j,k,current_num=0;
	for(i=1;i<=9;i++){
		generate_numbers(ans,i,i,A,B);
	}
	sort(ans.begin(),ans.end());
	return ans;
}

int main(){
	int A,B;
	cin>>A>>B;
	vector <int> ans=stepnum(A,B);
	print_vector(ans);
	return 0;
}