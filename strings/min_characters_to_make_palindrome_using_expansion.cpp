#include <bits/stdc++.h>
using namespace std;

// Given an string A. The only operation allowed is to insert characters in the beginning of the string.

// Find how many minimum characters are needed to be inserted to make the string a palindrome string.


//here what we do is we consider each character as centre of palindrome and also two consecutive characters as the centre pair
//in case of even characters long palindrome(two seperate loops as can be seen), expand the start && end,
//whenever start reaches left end, we add remaining characters ahead of end, in front of the string to create a palindrome,
//we choose the case where we had to attend minimum num of characters.

int solve(string A) {
    int i,j,k,len=A.size()-1;
    int start,end;
    for(i=0;i<A.size();i++){
        start=i,end=i;
        while(start>=0 && end<A.size()){
            if(A[start]==A[end]){
                start--;
                end++;
            }
            else{
                break;
            }
        }
        if(start==-1){
            if(A.size()-end<len){
                len=A.size()-end;
            }
        }
    }
    for(i=0;i<A.size()-1;i++){
        start=i,end=i+1;
        while(start>=0 && end<A.size()){
            if(A[start]==A[end]){
                start--;
                end++;
            }
            else{
                break;
            }
        }
        if(start==-1){
            if(A.size()-end<len){
                len=A.size()-end;
            }
        }
    }
    return len;
}
