#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool check_validity(string &x){
    if(x.size()>2){
        return false;
    }
    if(x.size()==1){
        if(x[0]=='0'){
            return false;
        }
        else{
            return true;
        }
    }
    if(x.size()==2){
        int t=0;
        t=10*(int)(x[0]-'0')+(x[1]-'0');
        if(t>=1 && t<=26){
            return true;
        }
        else{
            return false;
        }
    }
    
}

//Almost fibonacci but have to take care of the strings numerals and their limits.

int Solution::numDecodings(string A) {
    if(A.size()==0){
        return 1;
    }
    if(A.size()==1){
        if(A[0]=='0'){
            return 0;
        }
        return 1;
    }
    if(A[0]=='0'){
        return 0;
    }
    if(A[A.size()-1]=='0'&&A[A.size()-2]=='0'){
        return 0;
    }
    int prev,prev2prev;
    prev2prev=1;
    prev=1;
    int current_ans;
    int i=1;
    if(A[1]=='0'){
        string temp2;
        temp2.push_back(A[0]);
        temp2.push_back(A[1]);
        if(check_validity(temp2)==false){
            return 0;
        }
        else{
            current_ans=1;
            prev2prev=prev;
            prev=current_ans;
            i=2;
        }
    }
    for(;i<A.size();i++){
        string temp;
        temp.push_back(A[i-1]);
        temp.push_back(A[i]);
        //cout<<"temp: "<<temp<<" ";
        current_ans=0;
        if(i+1<A.size() && A[i+1]=='0'){
            string temp1;
            temp1.push_back(A[i]);
            temp1.push_back(A[i+1]);
            if(check_validity(temp1)==false){
                return 0;
            }
            else{
                current_ans=prev;
                i++;
            }
        }
        else if(A[i]=='0'){
            return 0;
        }
        else if(A[i-1]=='0'){
        //    cout<<"here"<<endl;
            current_ans=prev;
        }
        else if(check_validity(temp)==true){
        //    cout<<"here1"<<endl;
            current_ans=prev+prev2prev;
        }
        else if(A[i]>'0'){
        //    cout<<"here2"<<endl;
            current_ans=prev;
        }
        //cout<<"i:"<<i<<" current_ans:"<<current_ans<<endl;
        prev2prev=prev;
        prev=current_ans;
        
    }
    return current_ans;
}
