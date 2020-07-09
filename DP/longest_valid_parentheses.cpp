#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

// 1) Create an array longest of length n (size of the input string) initialized to zero.
//    The array will store
//    the length of the longest valid substring ending at that index.

// 2) Initialize result as 0.

// 3) Iterate through the string from second character
//    a) If the character is '(' set longest[i]=0 as no valid sub-string will end with '('.
//    b) Else
//       i) if s[i-1] = '('
//             set longest[i] = longest[i-2] + 2
//       ii) else
//             set longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

// 4) In each iteration update result as the maximum of result and longest[i]

// 5) Return result.
int longestValidParentheses(string &A) {
 if (A.length() <= 1) return 0; 
      
    //Initialize curMax to zero 
    int curMax = 0; 
  
    vector<int> longest(A.size(), 0); 
  
    //Iterate over the string starting from second index 
    for (int i = 1; i < A.length(); i++) { 
        if (A[i] == ')' && i - longest[i - 1] - 1 >= 0 && 
            A[i - longest[i - 1] - 1] == '(') { 
                longest[i] = longest[i - 1] + 2 +  
                ((i - longest[i - 1] - 2 >= 0)  
                ? longest[i - longest[i - 1] - 2] : 0); 
                    curMax = max(longest[i], curMax); 
        } 
    } 
    return curMax; 
}

int main(){
    string A="((())";
    cout<<longestValidParentheses(A)<<endl;
    return 0;
}