#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_array(vector <vector<int>> A){
    int i,j;
    cout<<"printing array: "<<endl;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"finished"<<endl;
}

bool compareinterval(vector <int> a, vector <int> b){
    if(a[1]!=b[1]){
        return a[1]<b[1];
    }
    else{
        return a[0]<b[0];
    }
}

long arrayManipulation(int n, vector<vector<int>> queries) {
    sort(queries.begin(),queries.end(),compareinterval);
    cout<<"sorted:"<<endl;

    print_array(queries);

    int i=0,j;
    long max=INT_MIN;
    i=0;
    int output_index;
    while(i<queries.size()){
        long sum=0;
        sum+=queries[i][2];
        j=i+1;
        int equality=0;
        while(j<queries.size()){
            if(queries[j][0]<queries[i][1]){
                sum+=queries[j][2];
                j++;
            }
            else if(queries[j][0]==queries[i][1]){
                equality++;
                j++;
                sum+=queries[j][2];
                break;
            }
            else{
                break;
            }
        }
        if (sum>max){
            max=sum;
            output_index=queries[j][1];
        }
        i=j-equality;
    }
    cout<<"max value index:"<<output_index<<endl;
    return max;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector <vector <int>> A;
    int t;
    for(int i=0;i<m;i++){
        vector <int> temp;
        for(int j=0;j<3;j++){
            cin>>t;
            temp.push_back(t);
        }
        A.push_back(temp);
    }
    cout<<"Ans: "<<arrayManipulation(n,A)<<endl;
    return 0;
}