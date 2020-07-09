#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//with only 2 transactions allowed. construct an array DP to store max profit from 0 to i, and another array to store max_profit from
//i+1  to lastindex DPrev. and then find the max of DP[i]+DPrev[i+1]. Finally also find max(max_ans,DP[A.size()-1]). We r done.

int maxProfit(const vector<int> &A) {
    if(A.size()==1||A.size()==0){
        return 0;
    }
    vector <int> DP(A.size(),0);
    int min_element=A[0];
    int i;
    for(i=1;i<DP.size();i++){
        DP[i]=max(DP[i-1],A[i]-min_element);
        min_element=min(A[i],min_element);
    }
    if(A.size()<=3){
        return DP[A.size()-1];
    }
    vector <int> DPrev(A.size(),0);
    int max_element=A[A.size()-1];
    for(i=A.size()-2;i>=0;i--){
        DPrev[i]=max(DPrev[i+1],max_element-A[i]);
        max_element=max(A[i],max_element);
    }
    max_element=0;
    for(i=0;i<A.size()-1;i++){
        max_element=max(DP[i]+DPrev[i+1],max_element);
    }
    max_element=max(max_element,DP[A.size()-1]);
    return max_element;
}

int main(){

}
