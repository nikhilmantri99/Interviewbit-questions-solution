#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int Solution::chordCnt(int A) {
//     If we draw a chord between any two points, can you observe the current set of points
//getting broken into two smaller sets S_1 and S_2. If we draw a chord from a point in S_1 
//to a point in S_2, it will surely intersect the chord we’ve just drawn.
// So, we can arrive at a recurrence that Ways(n) = sum[i = 0 to n-1] { Ways(i)*Ways(n-i-1) }.
// Here we iterate over i, assuming that size of one of the sets is i and size of another set
//automatically is (n-i-1) since we’ve already used a pair of points and i pair of points in 
//one set.
    int M=pow(10,9)+7;
    if(A==0 || A==1){
        return 1;
    }
    if(A==2){
        return 2;
    }
    int i,j,n=A;
    long long int arr[A+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(i=3;i<=A;i++){
        arr[i]=0;
        for(j=0;j<=i-1;j++){
            arr[i]=((arr[i])%M+(((arr[j])%M)*((arr[i-j-1])%M)))%M;
        }
        //cout<<arr[i]<<endl;
    }
    return arr[A];
}
