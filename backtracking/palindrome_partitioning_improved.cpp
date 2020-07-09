#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool ispalindrome(string &temp,int start, int end){
    if(start>end){
        return false;
    }
    while(start<end){
        if(temp[start]!=temp[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void update_ans(int start, string &A, vector <vector<string>> &ans, vector <string> &temp){
    if(start>=A.size()){
        ans.push_back(temp);
        return ;
    }
    int i,j,k;
    for(i=start;i<A.size();i++){
        if(ispalindrome(A,start,i)){
            temp.push_back(A.substr(start,i-start+1));
            update_ans(i+1,A,ans,temp);
            temp.erase(temp.end()-1);
        }
    }
    return;
}

vector<vector<string> > partition(string A) {
    vector <vector <string>> ans;
    vector <string> temp;
    update_ans(0,A,ans,temp);
    return ans;
}

int main(){
    string A="aab";
    vector <vector<string>> ans=partition(A);
    return 0;
}
