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
int peakElement(vector <int> arr, int low, int high, int lowerBound, int upperBound)
{
    int mid = low + (high - low) / 2;
     
    if (mid == lowerBound) {
        if (mid == upperBound) {
            // Only 1 element
            return mid;
        } else if (arr[mid] >= arr[mid + 1]) {
            // Pivot is the greater element
            return mid;
        }
    } else if (mid == upperBound) {
        if (arr[mid] >= arr[mid - 1]) {
            // Pivot is the greater element
            return mid;
        }
    } else {
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]) {
            // Mid value is the pivot
            return mid;
        } else if (arr[mid] > arr[high]) {
            // The Pivot is in the second half
            return peakElement(arr, mid + 1, high, lowerBound, upperBound);
        } else if (arr[mid] < arr[high]) {
            // The Pivot is in the first half
            return peakElement(arr, low, mid - 1, lowerBound, upperBound);
        }
    }
     
    return -1;
}


int find_pivot(vector <int> &A){
	int mid=-1,low=0;int high=A.size()-1;
	while(low<=high){
		mid=(low+high)/2;
		cout<<"mid: "<<mid<<endl;
		if(mid>0 && mid<A.size()-1 && A[mid]>A[mid+1] && A[mid-1]<A[mid]){
			return mid;
		}
		else if(A[mid]>A[high]){
			cout<<"Searching between: "<<mid+1<<" "<<high<<endl;
			low=mid+1;
		}
		else{
			cout<<"Searching between: "<<low<<" "<<mid-1<<endl;
			high=mid-1;
		}
	}
	return mid;
}

int search_element(vector <int> &A,int value){
	int pivot_position=peakElement(A,0,A.size()-1,0,A.size()-1);
	cout<<pivot_position<<endl;
	int mid=-1,low=0,high=pivot_position;
	while(low<=high){
		mid=(low+high)/2;
		if(A[mid]==value){
			return 1;
		}
		else if(A[mid]<value){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	low=pivot_position+1,high=A.size()-1;
	while(low<=high){
		mid=(low+high)/2;
		if(A[mid]==value){
			return 1;
		}
		else if(A[mid]<value){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return -1;
}

int main(){
	vector <int> A={194, 195, 196, 197, 198, 199, 201, 203, 204, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 29, 30, 31, 32, 33, 34, 35, 36, 37, 39, 40, 42, 43, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 57, 58, 59, 60, 61, 63, 65, 66, 68, 69, 70, 71, 73, 74, 76, 77, 79, 80, 81, 82, 83, 84, 86, 87, 88, 89, 91, 92, 93, 94, 95, 97, 98, 99, 101, 103, 104, 105, 106, 107, 108, 109, 110, 113, 114, 115, 117, 118, 120, 121, 122, 123, 124, 127, 128, 130, 131, 133, 134, 135, 136, 137, 139, 140, 141, 142, 143, 144, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 158, 159, 160, 161, 162, 163, 164, 166, 167, 169, 170, 171, 172, 174, 175, 177, 178, 179, 181, 182, 184, 185, 187, 189, 190, 192, 193};
	int value;
	cin>>value;
	cout<<search_element(A,value)<<endl;
	return 0;	
}