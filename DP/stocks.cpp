#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int maxProfit(const vector<int> &A) {
    if(A.size()==0){
        return 0;
    }
    int i=0;
    int max_diff_so_far=0,min_element_so_far;
    min_element_so_far=A[0];
    for(i=1;i<A.size();i++){
        max_diff_so_far=max(max_diff_so_far,A[i]-min_element_so_far);
        min_element_so_far=min(min_element_so_far,A[i]);
    }
    return max_diff_so_far;
}

int main(){
    vector <int> A={1, 4, 5, 2, 4};
    cout<<maxProfit(A)<<endl;
    return 0;
}