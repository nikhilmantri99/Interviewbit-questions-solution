#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// self solution; Nice work
// what we do is we create a stack wherein we insert indices.
// we first build rectangles where we can extend the bars only to left to create a rectangle.
// we then do this for right. We then add both side answers and remove the intersection part that
// was counted twice. 

//Now when we look at a bar, we pop all those indices from top where the height is greater than or equal to current bar.
//Thus after that the width of our rectange is i-s.top() || i+1 if s.empty(), and the height is the current bar height of
//course.

int maxval(vector <int> &x){
	int m=INT_MIN;
	for(int i=0;i<x.size();i++){
		m=max(m,x[i]);
	}
	return m;
}

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int largestRectangleArea(vector<int> &A) {
	//print_vector(A);
	vector <int> ans(A.size(),0);
	stack <int> s;//indices of array values thus enables width with height storage together
	int i,j,k;
	for(i=0;i<A.size();i++){
		while(!s.empty() && A[s.top()]>=A[i]){
			s.pop();
		}
		if(s.empty()){
			ans[i]+=A[i]*(i+1);
		}
		else{
			ans[i]+=A[i]*abs(i-s.top());
		} 
		s.push(i);
	}
	//print_vector(ans);
	while(!s.empty()){
		s.pop();
	}
	//Now we look from the backside because rectangle can be extended both ways;
	for(i=A.size()-1;i>=0;i--){
		while(!s.empty() && A[s.top()]>=A[i]){
			s.pop();
		}
		if(s.empty()){
			ans[i]+=A[i]*(A.size()-i)-A[i];
		}
		else{
			ans[i]+=A[i]*abs(i-s.top())-A[i];
		}
		s.push(i);
	}
	//print_vector(ans);
	return maxval(ans);
}

int main(){
	vector <int> A={2, 1, 5, 6, 2, 3};
	cout<<largestRectangleArea(A)<<endl;
	return 0;
}
