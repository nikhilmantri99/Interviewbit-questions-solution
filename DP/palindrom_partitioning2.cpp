#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//we need to keep a track of all kinds of palindromes happening in thw string in an efficient manner.
//Because we need overall min_cuts. We cannot greedily go on collecting longest palindromes from start.
//hence we maintain a dp array to maintain the minimum number of palindromes till an index and then greedily 
 //move ahead from that index.

void print_string(string &A,int left,int right){
    cout<<A.substr(left,right-left+1)<<endl;
}

bool is_palindrome(string &A, int left, int right){
    if(left==right){
        return true;
    }
    while(left<=right){
        if(A[left]==A[right]){
            left++;
            right--;
        }
        else{
            return false;
        }
    }
    return true;
}

int minCut(string A) {
    int n=A.size();
    int curr_left=0, curr_right=0;
    int i,j;
    int cuts=0;
    vector <int> dp(A.size(),INT_MAX);
    vector <int> starts;
    int min_cuts=INT_MAX;
    int k=0;
    while(k<A.size()){
        i=k;
        while(i<A.size()){
            if(i==0){
                cuts=0;
            }
            else{
                cuts=dp[i-1];
            }
            j=i;
            while(j<A.size()){
                if(is_palindrome(A,i,j)==true){
                    curr_right=j;
                    if(i==0){
                        dp[j]=min(dp[j],1);
                    }
                    else{
                        dp[j]=min(dp[j],dp[i-1]+1);
                    }
                }
                j++;
            }
            //print_string(A,curr_left,curr_right);
            curr_left=curr_right+1;
            curr_right=curr_left;
            cuts++;
            i=curr_left;
        }
        min_cuts=min(min_cuts,cuts);
        k++;
    }
    return min_cuts-1;
}

int main(){
    string A="bbab";
    cout<<minCut(A)<<endl;
    return 0;
}