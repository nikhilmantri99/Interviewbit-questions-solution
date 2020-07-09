#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_vector (vector <int> &x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void print_grid(vector <vector <int>> &t){
    for(int i=0;i<t.size();i++){
        print_vector(t[i]);
    }
    cout<<endl;
}

void update_ans(vector<vector <int>> &ans ,vector <int> &temp, int n, int k, int start ){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    if(start>n){
        return;
    }
    int i,j;
    for(int i=start;i<=n-(k-temp.size())+1;i++){
        temp.push_back(i);
        update_ans(ans,temp,n,k,i+1);
        temp.erase(temp.end()-1);
    }
    return;
}
vector<vector<int> > combine(int A, int B) {//n,k
    vector <vector <int>> ans;
    if(B>A || B==0){
        return ans;
    }
    vector <int> temp;
    update_ans(ans,temp,A,B,1);
    return ans;
}

int main(){
    vector <vector <int>> ans=combine(4,2);
    print_grid(ans);
    return 0;
}
