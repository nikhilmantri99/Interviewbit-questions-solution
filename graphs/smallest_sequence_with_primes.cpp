#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//We use this almost DJikstra kind of approach ans mainatain a set instead of pq, because easy to code.
//We break the innermost loop at the first smallest unseen product .

void print_vec(vector <int> &A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

vector<int> solve(int A, int B, int C, int D) {
    unordered_set <int> uset;
    int i,j,k;
    vector <int> primes;
    primes.push_back(A);
    primes.push_back(B);
    primes.push_back(C);
    sort(primes.begin(),primes.end());
    vector <int> ans(D+1,INT_MAX);
    ans[0]=1;
    uset.insert(1);
    for(i=1;i<ans.size();i++){
        for(k=0;k<i;k++){
            for(j=0;j<primes.size();j++){
                if(uset.find(ans[k]*primes[j])==uset.end()){
                    ans[i]=min(ans[i],ans[k]*primes[j]);
                    break;
                }
            }
        }
        //cout<<ans[i]<<endl;
        uset.insert(ans[i]);
    }
    ans.erase(ans.begin());
    return ans;
}

int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    vector <int> ans=solve(A,B,C,D);
    print_vec(ans);
    return 0;
}