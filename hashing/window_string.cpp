#include <bits/stdc++.h>
#include <iostream>

using namespace std;


// First check if the length of string is less than the length of the given pattern, if yes then “no such window can exist “.
// Store the occurrence of characters of the given pattern in a hash_pat[].
// Start matching the characters of pattern with the characters of string i.e. increment count if a character matches.
// Check if (count == length of pattern ) this means a window is found.
// If such window found, try to minimize it by removing extra characters from the beginning of the current window.
// Update min_length.
// Print the minimum length window.



void print_umap(unordered_map <char,int> &umap){
    int i,j,k;
    for(auto x:umap){
        cout<<x.first<<":"<<x.second<<" ";
    }
    cout<<endl;
}

string minWindow(string A, string B) {
    unordered_map <char,int> umap,hmap;
    string ans;
    if(B.size()>A.size()){
        return ans;
    }
    int i,j,k;
    for(i=0;i<B.size();i++){
        if(hmap.find(B[i])==hmap.end()){
            hmap[B[i]]=1;
        }
        else{
            hmap[B[i]]++;
        }
    }
    for(auto x:hmap){
        umap[x.first]=0;
    }
    int n=B.size();
    i=0;j=0;int count=0;//this count will tell us after what point we are ready to enter the inner if condition
    while(j<A.size()){
        if(umap.find(A[j])==umap.end()){
            j++;
            continue;
        }
        umap[A[j]]++;
        if(umap[A[j]]<=hmap[A[j]]){
            count++;
        }
        if(j-i+1>=n && count==n){
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            int flag=0;
            if(flag==0){
                //cout<<"here"<<endl;
                //print_umap(umap);
                while(j-i+1>=n && ((umap.find(A[i])!=umap.end() && umap[A[i]]>hmap[A[i]]) || umap.find(A[i])==umap.end())){
                    if(umap.find(A[i])!=umap.end()){
                        umap[A[i]]--;
                    }
                    i++;
                }
                //cout<<"Post removing from start i:"<<i<<" j:"<<j<<endl;
                if(ans.size()==0){
                    ans=A.substr(i,j-i+1);
                }
                else if(j-i+1<ans.size()){
                    ans=A.substr(i,j-i+1);
                }
            }
        }
        j++;
    }
    return ans;
}

int main(){
    string A="ADOBECODEBANC";
    string B="ABC";
    string ans=minWindow(A,B);
    cout<<ans<<endl;
    return 0;
}