#include <bits/stdc++.h>
using namespace std;

void print_vector(vector <int> &A){
    int i;
    for(i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int solve(vector<int> &A) {
    sort(A.begin(),A.end());
    print_vector(A);
    int i,j;
    i=0;
    while(i<A.size()){
        j=i;
        while(A[j]==A[i]){
            j++;
        }
        if(A[i]==A.size()-j){
            return 1;
        }
        i=j;
    }
    return -1;
}

int main(){
    vector <int> A;
    A.push_back(-4);
    A.push_back(-2);
    A.push_back(0);
    A.push_back(-1);
    A.push_back(-6);
    cout<<solve(A)<<endl;
}