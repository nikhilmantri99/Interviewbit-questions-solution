#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int lengthOfLongestSubstring(string A) {
    int len=1;
    int i,j,k;
    i=0;
    while(i<A.size()){
        j=i;
        unordered_map <char, int> umap;
        while(j<A.size()){
            if(umap.find(A[j])!=umap.end()){
                len=max(j-i,len);
                i=umap[A[j]]+1;
                break;
            }
            else{
                umap[A[j]]=j;
            }
            j++;
        }
        if(j==A.size()){
            len=max(j-i,len);
            return len;
        }
    }
}

int main(){
    string A="dadbc";
    cout<<lengthOfLongestSubstring(A)<<endl;
    return 0;
}
