//Question: Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
// Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void print_matrix(vector<vector<int>> &A){
    cout<<"Matrix Status:"<<endl;
    int i,j;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}


void change_row(vector<vector<int>> &A,int i){
    int j;
    for(j=0;j<A[i].size();j++){
        A[i][j]=0;
    }
}

void change_column(vector<vector<int> > &A,int j){
    int i;
    for(i=0;i<A.size();i++){
        A[i][j]=0;
    }
}

void setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector <int> rows;
    vector <int> columns;
    int i,j;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            if(A[i][j]==0){
                rows.push_back(i);
                break;
            }
        }
    }
    for(j=0;j<A[0].size();j++){
        for(i=0;i<A.size();i++){
            if(A[i][j]==0){
                columns.push_back(j);
                break;
            }
        }
    }
    if(rows.size()==0 || columns.size()==0){
        return;
    }
    for(i=0;i<rows.size();i++){
        change_row(A,rows[i]);
    }
    for(i=0;i<columns.size();i++){
        change_column(A,columns[i]);
    }
}

int main(){
    vector<vector<int>>A;
    vector<int>temp,temp1,temp2;
    temp.push_back(1);temp.push_back(0);temp.push_back(1);A.push_back(temp);
    temp1.push_back(1);temp1.push_back(1);temp1.push_back(1);A.push_back(temp1);
    temp2.push_back(1);temp2.push_back(0);temp2.push_back(1);A.push_back(temp2);
    print_matrix(A);
    setZeroes(A);
    print_matrix(A);
    return 0;
}