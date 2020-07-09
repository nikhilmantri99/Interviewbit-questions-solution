#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Approach:
// Suppose the number of inversions in the left half and right half of the array (let be inv1 and inv2), what kinds of inversions are not accounted for in Inv1 + Inv2? The answer is – the inversions that need to be counted during the merge step. Therefore, to get a number of inversions, that needs to be added a number of inversions in the left subarray, right subarray and merge().

// inv_count1
// How to get number of inversions in merge()?
// In merge process, let i is used for indexing left sub-array and j for right sub-array. At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

// inv_count2

// The complete picture:
// inv_count3
// Algorithm:

// 1. The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
// 2. Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index for first half and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
// 3. Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, number of inversion in the second half and the number of inversions by merging the two.
// 4. The base case of recursion is when there is only one element in the given half.
// 5. Print the answer

void print_vec(vector <int> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void merge(vector <int> &A,int left,int mid, int right,int &ans){
    //cout<<"left:"<<left<<" mid:"<<mid<<" right:"<<right<<endl;
    if(left>=right){
        return;
    }
    vector <int> temp(right-left+1);
    int i=left;
    int j=mid+1;
    int pos=0;
    while(i<=mid || j<=right){
        if(i>mid){
            temp[pos]=A[j];
            j++;
        }
        else if(j>right){
            temp[pos]=A[i];
            i++;
        }
        else if(A[i]<=A[j]){
            temp[pos]=A[i];
            i++;
        }
        else{
            ans+=(int)abs(mid-i+1);
            temp[pos]=A[j];
            j++;
        }
        pos++;
    }
    //print_vec(temp);
    i=left;
    j=0;
    while(i<=right){
        A[i]=temp[j];
        i++;
        j++;
    }
    return ;
}

void mergesort(vector <int> &A, int i,int j,int &ans){
    if(i>=j){
        return;
    }
    int mid=i+(j-i)/2;
    mergesort(A,i,mid,ans);
    mergesort(A,mid+1,j,ans);
    merge(A,i,mid,j,ans);
}

int countInversions(vector<int> &A) {
    int ans=0;
    mergesort(A,0,A.size()-1,ans);
    return ans;
}
