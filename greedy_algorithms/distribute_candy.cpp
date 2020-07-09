#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int candy(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int i,j,k;
    vector <int> ans(n,1);
    for(i=0;i<n-1;i++){
        if(A[i]<A[i+1]){
            ans[i+1]=ans[i]+1;
        }
        else if(A[i]>A[i+1] && ans[i]<=ans[i+1]){
            ans[i]=ans[i+1]+1;
            j=i-1;
            while(A[j]>A[j+1] && j>=0 && ans[j]<=ans[j+1]){
                ans[j]=ans[j+1]+1;
                j--;
            }
        }
    }
    int sum=0;
    for(i=0;i<ans.size();i++){
        sum+=ans[i];
    }
    return sum;
}
