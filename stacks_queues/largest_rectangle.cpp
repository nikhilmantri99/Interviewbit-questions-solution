#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// For every bar ‘x’, we calculate the area with ‘x’ as the 
// smallest bar in the rectangle. If we calculate such area 
// for every bar ‘x’ and find the maximum of all areas, our 
// task is done. How to calculate area with ‘x’ as smallest bar?
// We need to know index of the first smaller (smaller than ‘x’) 
// bar on left of ‘x’ and index of first smaller bar on right of ‘x’. 
// Let us call these indexes as ‘left index’ and ‘right index’ respectively.
// We traverse all bars from left to right, maintain a stack of bars.
// Every bar is pushed to stack once. A bar is popped from stack when 
// a bar of smaller height is seen. When a bar is popped, we calculate 
// the area with the popped bar as smallest bar. How do we get left 
// and right indexes of the popped bar – the current index tells us 
// the ‘right index’ and index of previous item in stack is the ‘left index’.
// Following is the complete algorithm.

int largestRectangleArea(vector<int> &A) {
   // Create an empty stack. The stack holds indexes  
    // of hist[] array. The bars stored in stack are  
    // always in increasing order of their heights. 
    stack<int> s; 
    int n=A.size();
    int max_area = 0; // Initialize max area 
    int tp;  // To store top of stack 
    int area_with_top; // To store area with top bar 
                       // as the smallest bar 
  
    // Run through all bars of given histogram 
    int i = 0; 
    while (i < n) 
    { 
        // If this bar is higher than the bar on top  
        // stack, push it to stack 
        if (s.empty() || A[s.top()] <= A[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack,  
        // then calculate area of rectangle with stack  
        // top as the smallest (or minimum height) bar.  
        // 'i' is 'right index' for the top and element  
        // before top in stack is 'left index' 
        else
        { 
            tp = s.top();  // store the top index 
            s.pop();  // pop the top 
  
            // Calculate the area with hist[tp] stack  
            // as smallest bar 
            area_with_top = A[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 
  
            // update max area, if needed 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate 
    // area with every popped bar as the smallest bar 
    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = A[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
}

int main(){
	vector <int> A={2, 1, 5, 6, 2, 3};
	cout<<largestRectangleArea(A)<<endl;
	return 0;
}
