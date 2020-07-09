#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

vector<int> findSubstring(string A, const vector<string> &B) {
    if(A.size()<(B.size()*B[0].size())){
        vector <int> ans;
        return ans;
    }
    unordered_map <string,int> collection;
    int L=B[0].size();
    int n=B.size();
    for(int i=0;i<B.size();i++){
        if(collection.find(B[i])==collection.end()){
            collection[B[i]]=1;
        }
        else{
            collection[B[i]]++;
        }
    }
    vector <int> ans;
    int i,j;
    for(i=0;i<=A.size()-n*L;i++){
        unordered_map <string,int> temp_hmap=collection;
        for(j=i;j<i+n*L;){
            string temp=A.substr(j,L);
            if(temp_hmap.find(temp)==temp_hmap.end()){
                break;
            }
            else{
                temp_hmap[temp]--;
            }
            j=j+L;
        }
        int flag=0;
        for(auto x:temp_hmap){
            if(x.second!=0){
                flag++;
                continue;
            }
        }
        if(flag==0) ans.push_back(i);
    }
    return ans;
}

int main(){
    string A="barfoothefoobarman";
    vector <string> B={"foo", "bar"};
    vector <int> ans=findSubstring(A,B);
    print_vector(ans);
    return 0;
}
