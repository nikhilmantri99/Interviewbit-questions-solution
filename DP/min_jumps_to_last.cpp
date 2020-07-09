#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int jump(vector<int> &A) {
	if(A.size()==0 || A.size()==1){
		return 0;
	}
	int i,j;
	vector <int> jumps(A.size(),INT_MAX);
	vector <bool> reachable(A.size(),false);
	jumps[0]=0;
	reachable[0]=true;
	for(i=0;i<A.size();i++){
		if(reachable[i]==false || A[i]==0){
			continue;
		}
		else{
			for(j=1;j<=A[i] && i+j<A.size();j++){
				reachable[i+j]=true;
				jumps[i+j]=min(jumps[i+j],jumps[i]+1);
			}
		}	
	}
	print_vector(jumps);
	if(reachable[A.size()-1]==false){
		return -1;
	}
	else{
		return jumps[A.size()-1];
	}
}


//optimized solution
int jump2(vector<int> &A) {
   // The number of jumps needed to reach the starting index is 0 
    int n=A.size();
    if (n <= 1) 
        return 0; 
  
    // Return -1 if not possible to jump 
    if (A[0] == 0) 
        return -1; 
  
    // initialization 
    int maxReach = A[0];  // stores all time the maximal reachable index in the array. 
    int step = A[0];      // stores the number of steps we can still take 
    int jump =1;//stores the number of jumps necessary to reach that maximal reachable position. 
  
    // Start traversing array 
    int i=1; 
    for (i = 1; i < n; i++) 
    { 
        // Check if we have reached the end of the array 
        if (i == n-1) 
            return jump; 
  
        // updating maxReach 
        maxReach = max(maxReach, i+A[i]); 
  
        // we use a step to get to the current index 
        step--; 
  
        // If no further steps left 
        if (step == 0) 
        { 
            // we must have used a jump 
            jump++; 
  
            // Check if the current index/position or lesser index 
            // is the maximum reach point from the previous indexes 
            if(i >= maxReach) 
                return -1; 
  
            // re-initialize the steps to the amount 
            // of steps to reach maxReach from position i. 
            step = maxReach - i; 
        } 
    } 
  
    return -1; 
}

int main(){
	vector <int> A={2,3,1,1,4};
	cout<<jump(A)<<endl;
	cout<<jump2(A)<<endl;
	return 0;
}
