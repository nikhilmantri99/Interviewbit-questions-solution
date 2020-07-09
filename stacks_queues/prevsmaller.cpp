#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Question: Given an array of integers, 
// find the nearest smaller number
// for every element such that the smaller element is on left side.


// Below is stack based algorithm

// Let input sequence be 'arr[]' and size of array be 'n'

// 1) Create a new empty stack S

// 2) For every element 'arr[i]' in the input sequence 'arr[]',
//    where 'i' goes from 0 to n-1.
//     a) while S is nonempty and the top element of 
//        S is greater than or equal to 'arr[i]':
//            pop S
    
//     b) if S is empty:
//            'arr[i]' has no preceding smaller value
//     c) else:
//            the nearest smaller value to 'arr[i]' is 
//            the top element of S

//     d) push 'arr[i]' onto S

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

vector<int> prevSmaller(vector<int> &A){
	vector <int> G;
	stack <int> s;
	for(int i=0;i<A.size();i++){
		while(s.empty()==false){
			if(A[i]<=s.top()){
				s.pop();
			}
			else{
				break;
			}
		}
		if(s.empty()==true){
			G.push_back(-1);
		}
		else{
			G.push_back(s.top());
		}
		s.push(A[i]);
	}
	return G;
}

int main(){
	vector <int> A={4, 5, 2, 10, 8};
	vector <int> B={3, 2, 1};
	vector <int> ans=prevSmaller(B);
	print_vector(ans);
	return 0;
}
