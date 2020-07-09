#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct timing{
	int a;
	int d;
};

bool compare(struct timing x,struct timing y){
	if(x.a<y.a){
		return true;
	}
	else if(x.a>y.a){
		return false;
	}
	else{
		if(x.d<=y.d){
			return true;
		}
		else{
			return false;
		}
	}
}

void print_sorted(const vector <struct timing> &A){
	for(int i=0;i<A.size();i++){
		cout<<A[i].a<<" "<<A[i].d<<endl;
	}
}

bool hotel(vector <int> &arrive, vector<int> &depart, int K) {
	int i,j,k,n=arrive.size();
	vector <struct timing> rooms;
	vector <struct timing> customers;
	struct timing temp;
		temp.a=0;
		temp.d=0;
	for(i=0;i<K;i++){
		rooms.push_back(temp);
	}
	for(i=0;i<arrive.size();i++){
		temp.a=arrive[i];
		temp.d=depart[i];
		customers.push_back(temp);
	}
	sort(customers.begin(),customers.end(),compare);
	cout<<"sorted"<<endl;
	print_sorted(customers);
	cout<<"moving to loops"<<endl;
	j=0;
	for(i=0;i<n;i++){
		int found=0;
		cout<<"printing rooms:\n";
		print_sorted(rooms);
		cout<<"checks"<<endl;
		for(j=0;j<K;j++){
			if(rooms[j].d<=customers[i].a){
				rooms[j].a=customers[i].a;
				rooms[j].d=customers[i].d;
				found++;
				break;
			}
		}
		if(found==0){
				return false;
		}
	}
	return true;
}

bool hotel1(vector <int> &arrive, vector<int> &depart, int K) {
	int i,j,k,n=arrive.size();
	//vector <struct timing> rooms;
	vector <struct timing> customers;
	struct timing temp;
		temp.a=0;
		temp.d=0;
	for(i=0;i<arrive.size();i++){
		temp.a=arrive[i];
		temp.d=depart[i];
		customers.push_back(temp);
	}
	sort(customers.begin(),customers.end(),compare);
	cout<<"sorted"<<endl;
	print_sorted(customers);
	cout<<"moving to loops"<<endl;
	j=0;
	for(i=0;i<n;i++){
		
	}
}


int main(){
	vector<int> arrive;
	vector<int> depart;
	int n,i,j,k;
	k=1;
	arrive.push_back(1);
	arrive.push_back(2);
	arrive.push_back(3);
	arrive.push_back(4);

	depart.push_back(10);
	depart.push_back(2);
	depart.push_back(6);
	depart.push_back(14);
	cout<<hotel(arrive,depart,k)<<endl;;
	return 0;
}
