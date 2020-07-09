/*You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.*/

#include <bits/stdc++.h> 
using namespace std; 

int maximum(int A,int B){
    if(A>B){
        return A;
    }
    else{
        return B;
    }
}

int maxArr(vector<int> &A) {
    //open the mod, bring together i and j and form the cases.
    int max1=INT_MIN,min1=INT_MAX;//for A[i]+i
    int max2=INT_MIN,min2=INT_MAX;//for A[i]-i
    for(int i=0;i<A.size();i++){
        if (A[i]+i>max1){
            max1=A[i]+i;
        }
        if (A[i]+i<min1){
            min1=A[i]+i;
        }
        if (A[i]-i>max2){
            max2=A[i]-i;
        }
        if(A[i]-i<min2){
            min2=A[i]-i;
        }
    }
    return max(max1-min1,max2-min2);
}

int main(){
    int n;
    vector <int> x;
    // cin>>n;
    // int i;
    // for(i=0;i<n;i++){
    //     int temp;
    //     cin>>temp;
    //     x.push_back(temp);
    // }
    // cout<<"here"<<endl;
    // cout<<maxArr(x)<<endl;
    x.push_back(-70);
    x.push_back(-64);
    x.push_back(-6);
    x.push_back(-56);
    x.push_back(64);
    x.push_back(61);
    x.push_back(-57);
    x.push_back(16);
    x.push_back(48);
    x.push_back(-98);
    cout<<maxArr(x)<<endl;
    return 0;
}