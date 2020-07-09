#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//greedy approach works in this case. no like min_coins required for exchange. Here just everytime pick the fibonacci number,
// just less than or equal to given number. increment count . subtract that fin number and call for remaining number recursively.

int fibsum(int A) {
    if(A==0){
        return 0;
    }
    if(A<=3){
        return 1;
    }
    // vector <bool> is_fib(A+1,false);
    // is_fib[1]=true;
    // is_fib[2]=true;
    int preprev=1;
    int prev=2;
    int current;
    while(preprev+prev<=A){
        current=prev+preprev;
        //cout<<current<<" ";
        preprev=prev;
        prev=current;
    }
    //cout<<endl;
    //cout<<current<<endl;
    return 1+fibsum(A-current);
}


int main(){
    int x;
    cin>>x;
    cout<<fibsum(x)<<endl;
    return 0;
}