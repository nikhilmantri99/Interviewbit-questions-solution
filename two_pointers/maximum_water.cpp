#include <bits/stdc++.h>
#include <iostream>

 using namespace std;

//Question: Given n non-negative integers a1, a2, ..., an,
// where each represents a point at coordinate (i, ai).
// 'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

// Find two lines, which together with x-axis forms a container, such that the container contains the most water.

    // Answer: This implies that if there was a better solution possible, it will definitely have the Height greater than min(a1, aN).
    // Base * Height > (N-1) * min(a_1, a_N)
    // We know that, Base min(a1, aN)
    // This means that we can discard min(a1, aN) from our set and look to solve this problem again from the start.
    // If a1 < aN, then the problem reduces to solving the same thing for a2, aN.
    // Else, it reduces to solving the same thing for a1, aN-1



int area(int i,int ai,int j,int aj){
	return abs(j-i)*min(ai,aj);
}

int maxArea(vector<int> &A) {
	int i,j,max_area=0;
	i=0,j=A.size()-1;
	while(i<j){
		int Area=area(i,A[i],j,A[j]);
		if(Area>max_area){
			max_area=Area;
		}
		if(min(A[i],A[j])==A[i]){
			i++;
		}
		else{
			j--;
		}
	}
	return max_area;
}

int main(){
	vector <int> A={1,5,4,3};
	cout<<maxArea(A)<<endl;
	return 0;
}
