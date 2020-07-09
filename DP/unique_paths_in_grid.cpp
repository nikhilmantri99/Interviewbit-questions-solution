#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>&A) {
    vector <int> L(A[0].size(),0);
    vector <vector<int>> ans; 
    int i,j;
    for(int i=0;i<A.size();i++){
        ans.push_back(L);
    }
    if(A[0][0]==1){
        return 0;
    }
    ans[0][0]=1;
    for(i=1;i<A[0].size();i++){
        if(A[0][i]==1){
            ans[0][i]=0;
        }
        else{
            ans[0][i]=ans[0][i-1];
        }
        //cout<<"i,j:"<<i<<" "<<j<<" paths:"<<ans[i][j]<<endl;
    }
    for(i=1;i<A.size();i++){
        if(A[i][0]==1){
            ans[i][0]=0;
        }
        else{
            ans[i][0]=ans[i-1][0];
        }
        //cout<<"i,j:"<<i<<" "<<j<<" paths:"<<ans[i][j]<<endl;
    }
    //cout<<"inside two loop: "<<endl;
    for(i=1;i<A.size();i++){
        for(j=1;j<A[0].size();j++){
            if(A[i][j]==1){
                ans[i][j]=0;
            }
            else{
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
            }
            //cout<<"i,j:"<<i<<" "<<j<<" paths:"<<ans[i][j]<<endl;
        }
    }
    return ans[A.size()-1][A[0].size()-1];
}