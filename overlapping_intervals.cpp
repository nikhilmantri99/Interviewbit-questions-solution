// Given a collection of intervals, merge all overlapping intervals.

// For example:

// Given [1,3],[2,6],[8,10],[15,18],

// return [1,6],[8,10],[15,18].

// Make sure the returned intervals are sorted.
#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;


struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

bool compare_func(Interval a, Interval b){
	if(a.start!=b.start){
		return a.start<b.start;
	}
	else{
		return a.end<b.end;
	}
}

void print_interval(vector <Interval> &x){
	cout<<"printing interval:"<<endl;
	int i;
	for(i=0;i<x.size();i++){
		cout<<x[i].start<<" "<<x[i].end<<endl;
	}
}

vector<Interval> merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n=A.size(),i=0,j;
	sort(A.begin(),A.end(),compare_func);
	vector <Interval> ans;
	Interval temp;
	while(i<n){
		if(i==n-1){
			ans.push_back(A[i]);
			return ans;
		}
		temp.start=A[i].start;
		int max=A[i].end;
		int maxindex=i;
		j=i+1;
		while(j<n){
			if(A[maxindex].end>=A[j].start){
				if(A[j].end>max){
					max=A[j].end;
					maxindex=j;
					j++;
					continue;
				}
				else{
					j++;
					continue;
				}
			}
			else{
				i=j;
				temp.end=max;
				ans.push_back(temp);
				break;
			}
		}
		if(j==n){
			temp.end=max;
			ans.push_back(temp);
			return ans;
		}
	}
	return ans;
}

int main(){
	int i,n;
	vector <Interval> A;
	Interval temp;
	cout<<"Given Interval Array:"<<endl;
	temp.start=1;temp.end=10;A.push_back(temp);
	temp.start=2;temp.end=9;A.push_back(temp);
	temp.start=3;temp.end=8;A.push_back(temp);
	temp.start=4;temp.end=7;A.push_back(temp);
	temp.start=5;temp.end=6;A.push_back(temp);
	temp.start=6;temp.end=6;A.push_back(temp);
	print_interval(A);
	vector <Interval> ans= merge(A);
	cout<<"After merge:"<<endl;
	print_interval(ans);
	return 0;
}
