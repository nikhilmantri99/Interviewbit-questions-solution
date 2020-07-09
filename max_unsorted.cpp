#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

vector<int> SubUnsort(vector<int> &A) {
    int i,j,k;
    int n=A.size();
    int left_index,right_index;
    for(i=0;i<=n-2;i++){
        //cout<<"left_check: "<<i<<endl;
        if (A[i]<=A[i+1]){
            continue;
        }
        else{
            break;
        }
    }
    left_index=i;
    for(i=n-1;i>=1;i--){
        if (A[i]>=A[i-1]){
            continue;
        }
        else{
            //right_index=i;
            break;
        }
    }
    right_index=i;
    vector <int> ans;
    //cout<<left_index<<" "<<right_index<<endl;
    if(left_index>=right_index){
        ans.push_back(-1);
        return ans;
    }
    ans.push_back(left_index);
    ans.push_back(right_index);
    return ans;
}

int main(){
    vector <int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    vector <int> ans=SubUnsort(t);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;

}