#include <bits/stdc++.h>
using namespace std;

// The pivot element is basically, the largest element in an array. For a sorted and rotated array, 
// it might be somewhere in between. We can solve this in O(log N) time, 
// through a divide-and-conquer approach, which is similar to peak finding algorithm. 
// We will have the lower limit (low) and the upper limit (high) from which we will calculate the ‘mid’. 
// Now, we must address a few cases –
// arr[mid] > arr[high] – If the mid element is greater than the last element, 
// then the pivot should be in the second half of the array. Why is this so? This is actually 
// because it is a sorted and rotated array. You may not understand this at first, but think of the values 
//of the elements in the array as a histogram.
// arr[mid] < arr[high] – If the mid element is less than the last element, then the pivot should be in the first half of the range.
// Pivot Element - Case 2
// If mid element is a peak – 
// If the mid element satisfies the property of the peak element (not lesser than its neighbors), then, it is the pivot.
int find_pivot(vector <int> &A){
	int mid=-1,low=0;int high=A.size()-1;
	while(low<=high){
		cout<<"mid: "<<mid<<endl;
		mid=(low+high)/2;
		if(mid>0 && mid<high && A[mid]>A[mid+1] && A[mid-1]<A[mid]){
			return mid;
		}
		else if(A[mid]>A[high]){
			cout<<"Searching between: "<<mid<<" "<<high<<endl;
			low=mid+1;
		}
		else{
			cout<<"Searching between: "<<low<<" "<<mid<<endl;
			high=mid-1;
		}
	}
	return mid;
}

int main(){
	vector <int> A={4,5,6,7,0,1,2,3};
	cout<<find_pivot(A)<<endl;
	return 0;	
}

