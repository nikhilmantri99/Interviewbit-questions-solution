#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string Solution::convertToTitle(int A) {
//     Suppose we have a number n, let’s say 28. 
//so corresponding to it we need to print the column name. We need to take remainder with 26.
// If remainder with 26 comes out to be 0 (meaning 26, 52 and so on) then we put ‘Z’ in the 
//output string and new n becomes n/26 -1 because here we are considering 26 to be ‘Z’ while in 
//actual it’s 25th with respect to ‘A’.
// Similarly if the remainder comes out to be non zero. (like 1, 2, 3 and so on) then we need to 
//just insert the char accordingly in the string and do n = n/26.
// Finally we reverse the string and print. 
    vector <char> vec={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
    string x;
    while(A!=0){
        int temp=A%26;
        x.push_back(vec[temp]);
        if(temp==0){
            A=A/26-1;
        }
        else{
            A=A/26;
        }
    }
    reverse(x.begin(),x.end());
    return x;
}
