#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int minPathSum(vector<vector<int>> &A) {
    
    vector <int> temp(A[0].size(),0);
    vector <vector<int>> ans;
    int i,j,k;
    for(i=0;i<A.size();i++){
        ans.push_back(temp);
    }
    int n_rows=A.size(),n_cols=A[0].size();
    ans[0][0]=A[0][0];
    for(i=1;i<n_rows;i++){
        //print_RC(i,0);
        ans[i][0]=ans[i-1][0]+A[i][0];
    }
    for(i=1;i<n_cols;i++){
        //print_RC(0,i);
        ans[0][i]=ans[0][i-1]+A[0][i];
    }
    for(i=1;i<n_rows;i++){
        for(j=1;j<n_cols;j++){
            //print_RC(i,j);
            ans[i][j]=A[i][j]+min(ans[i-1][j],ans[i][j-1]);
        }
    }
    //cout<<ans[n_rows-1][n_cols-1]<<endl;
    return ans[n_rows-1][n_cols-1];
}