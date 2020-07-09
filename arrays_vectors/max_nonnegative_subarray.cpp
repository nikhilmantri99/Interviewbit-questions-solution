#include <vector>
#include <string>
#include <cassert>
#include <algorithm> 
#include <stack>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


vector<int> maxset(vector<int> &A) {
    int i,reset=0,left_current=0,right_current=0,left_sofar=0,right_sofar=0,current_max=A[0],max_so_far=A[0];
    vector <int> output;
    i=0;
    while(i<A.size() && A[i]<0){
        i++;
    }
    if (i>=A.size()){
        return output;
    }
    left_current=i;
    right_current=i;
    left_sofar=i;
    right_sofar=i;
    current_max=A[i];
    max_so_far=A[i];
    int val=i;
    for(i=val+1;i<A.size();i++){
        if(A[i]<0){
            reset=1;
            continue;
        }
        if(reset==1){
            current_max=A[i];
            left_current=i;
            right_current=i;
        }
        else if(A[i]+current_max>A[i]){
            current_max=A[i]+current_max;
            right_current=i;
        }
        else{
            left_current=i;
            right_current=i;
            current_max=A[i];
        }
        if(current_max>max_so_far){
            max_so_far=current_max;
            left_sofar=left_current;
            right_sofar=right_current;
        }
        else if(current_max==max_so_far){
            if(right_current-left_current>right_sofar-left_sofar){
                left_sofar=left_current;
                right_sofar=right_current;
            }
        }
        reset=0;
    }
    cout<<left_sofar<<" "<<right_sofar<<endl;
    if (left_sofar==right_sofar){
        if (A[left_sofar]<0){
            return output;
        }
    }
    for(i=left_sofar;i<=right_sofar;i++){
        output.push_back(A[i]);
    }
    return output;
}

int main(){
    vector <int> A;
    A.push_back(0);
    A.push_back(0);
    A.push_back(-1);
    A.push_back(0);
    //A.push_back(-1);
    vector <int> b=maxset(A);
    return 0;
}