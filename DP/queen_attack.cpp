#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print_matrix_string(vector<string> &A){
    int i,j;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void print_matrix(vector<vector<int>> &A){
    int i,j;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


vector<vector<int> > queenAttack(vector<string> &A) {
    print_matrix_string(A);
    vector <vector<int>> ans(A.size(),vector <int> (A[0].size(),0));
    int i,j,k;
    for(i=0;i<A.size();i++){
        for(j=0;j<A[0].size();j++){
            if(A[i][j]=='1'){
                int k,l,flag=0;
                k=i+1;
                if(k<A.size() && A[k][j]=='1'){
                    ans[k][j]+=1;
                } 
                while(k<A.size() && A[k][j]!='1'){
                    ans[k][j]+=1;
                    if(k+1<A.size() && A[k+1][j]=='1'){
                        ans[k+1][j]+=1;
                    }
                    k++;
                }
                k=i-1;
                if(k>=0 && A[k][j]=='1'){
                    ans[k][j]+=1;
                }  
                while(k>=0 && A[k][j]!='1'){
                    ans[k][j]+=1;
                    if(k-1>=0 && A[k-1][j]=='1'){
                        ans[k-1][j]+=1;
                    }
                    k--;
                }
                k=j-1;
                if(k>=0 && A[i][k]=='1'){
                    ans[i][k]+=1;
                }   
                while(k>=0 && A[i][k]!='1'){
                    ans[i][k]+=1;
                    if(k-1>=0 && A[i][k-1]=='1'){
                        ans[i][k-1]+=1;
                    }
                    k--;
                }
                k=j+1;
                if(k<A[0].size() && A[i][k]=='1'){
                    ans[i][k]+=1;
                }   
                while(k<A[0].size() && A[i][k]!='1'){
                    ans[i][k]+=1;
                    if(k+1<A[0].size() && A[i][k+1]=='1'){
                        ans[i][k+1]+=1;
                    }
                    k++;
                }
                k=i+1;
                l=j+1;
                if(k<A.size() && l<A[0].size() && A[k][l]=='1'){
                    ans[k][l]+=1;
                }
                while(k<A.size() && l<A[0].size() && A[k][l]!='1'){
                    ans[k][l]+=1;
                    if(k+1<A.size() && l+1<A[0].size() && A[k+1][l+1]=='1'){
                        ans[k+1][l+1]+=1;
                    }
                    k++;
                    l++;
                }
                k=i-1;
                l=j-1;
                if(k>=0 && l>=0 && A[k][l]=='1'){
                    ans[k][l]+=1;
                }
                while(k>=0 && l>=0 && A[k][l]!='1'){
                    ans[k][l]+=1;
                    if(k-1>=0 && l-1>=0 && A[k-1][l-1]=='1'){
                        ans[k-1][l-1]+=1;
                    }
                    k--;
                    l--;
                }
                
                k=i+1;
                l=j-1;
                if(k<A.size() && l>=0 && A[k][l]=='1'){
                    ans[k][l]+=1;
                }
                while(k<A.size() && l>=0 && A[k][l]!='1'){
                    ans[k][l]+=1;
                    if(k+1<A.size() && l-1>=0 && A[k+1][l-1]=='1'){
                        ans[k+1][l-1]+=1;
                    }
                    k++;
                    l--;
                }
                
                k=i-1;
                l=j+1;
                if(k>=0 && l<A[0].size() && A[k][l]=='1'){
                    ans[k][l]+=1;
                }
                while(k>=0 && l<A[0].size() && A[k][l]!='1'){
                    ans[k][l]+=1;
                    if(k-1>=0 && l+1<A[0].size() && A[k-1][l+1]=='1'){
                        ans[k-1][l+1]+=1;
                    }
                    k--;
                    l++;
                }
            }
        }
    }
    print_matrix(ans);
    return ans;
}

int main(){
    vector <string> A={"010","100","001"};
    vector <vector<int>> ans=queenAttack(A);
    return 0;
}