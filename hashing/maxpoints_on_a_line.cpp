#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//take a point P, the points making the same slope with it will lie on the same line. Overlapping points with the current point P
//will 

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    if(A.size()==0){
        return 0;
    }
    if(A.size()==1){
        return 1;
    }
    if(A.size()==2){
        return 2;
    }
    int maxpoints=0;
    int i,j,k;
    for(i=0;i<A.size();i++){
        int overlap_points=0;
        int vertical_points=0;
        int current_max=0;
        unordered_map <double,int> umap;
        for(j=i+1;j<A.size();j++){
            double m;
            if(A[i]==A[j] && B[i]==B[j]){
                overlap_points++;
            }
            else if(A[i]==A[j]){
                vertical_points++;
            }
            else{
                double x=A[i]-A[j];
                double y=B[i]-B[j];
                m=y/x;
                if(umap.find(m)==umap.end()){
                    umap[m]=1;
                    current_max=max(current_max,umap[m]);
                }
                else{
                    umap[m]++;
                    current_max=max(current_max,umap[m]);
                }
            }
        }
        current_max=max(current_max,vertical_points);
        current_max=current_max+overlap_points+1;
        maxpoints=max(maxpoints,current_max);
    }
    return maxpoints;
}
