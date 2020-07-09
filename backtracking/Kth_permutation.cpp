#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int fact(int n)
{
    if(n==0 || n==1){
    	return 1;
    }
    if (n>12)   
        return INT_MAX;
    int f = 1;
    for (auto i = 2; i<=n; ++i)
        f *= i;
    return f;
}

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void update_temp(vector<int> &temp,vector <bool> &status,int digit,int n,int &current_reached,int target){
	if(status[digit]==false){
		cout<<"digit:"<<digit<<" is used"<<endl;
		int new_digit;
		if(digit==n){
			new_digit=1;
		}
		else{
			new_digit=digit+1;
		}
		update_temp(temp,status,new_digit,n,current_reached,target);
	}
	else if(fact(n-temp.size()-1)<target){
		cout<<"digit: "<<digit<<" factorial of remaining is less, moving on"<<endl;
		current_reached+=fact(n-temp.size()-1);
		cout<<"current_reached: "<<current_reached<<endl;
		int new_digit;
		if(digit==n){
			new_digit=1;
		}
		else{
			new_digit=digit+1;
		}
		cout<<"new_digit: "<<new_digit<<endl;
		update_temp(temp,status,new_digit,n,current_reached,target-fact(n-temp.size()-1));
	}
	else if(fact(n-temp.size()-1)>target){
		cout<<"choosing current digit for temp: "<<digit<<endl;
		temp.push_back(digit);
		print_vector(temp);
		status[digit]=false;
		update_temp(temp,status,1,n,current_reached,target);
	}
	else if(fact(n-temp.size()-1)==target){
		cout<<"the number stands at current temp + digit's ("<<digit<<") last permutation "<<digit<<endl;
		temp.push_back(digit);
		status[digit]=false;
		for(int i=n;i>=1;i--){
			if(status[i]==true){
				temp.push_back(i);
				status[i]=false;
			}
		}
		return;
	}
}

string getPermutation(int A, int B) {
	vector <bool> status;
	int i;
	vector <int> temp;
	int current_reached=0;
	for(i=0;i<=A;i++){
		status.push_back(true);
	}
	update_temp(temp,status,1,A,current_reached,B);
	string ans;
	print_vector(temp);
	for(i=0;i<temp.size();i++){
		ans.append(to_string(temp[i]));
	}
	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	cout<<getPermutation(n,k)<<endl;
	return 0;
}
