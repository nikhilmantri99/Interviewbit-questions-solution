//we can observe that product of factors will be n^(number of factor/2). 
//But when number of factor is odd (which means the number is perfect square) in that case product 
//will be n^(number of factor/2) * sqrt(n). We can count number of factors similar to approach above. 
//And we can calculate power efficiently using Modular Exponentiation
// C++ program to calculate product 
// of factors of number 
#include <bits/stdc++.h> 
#include <math.h>
#define M 1000000007 
using namespace std; 

struct num_freq{
    long long num;
    int freq;
};   
// Iterative Function to calculate 
// (x^y) in O(log y) 


long long power(long long x, long long y) 
{ 
    long long res = 1; 
  
    while (y > 0)  
    { 
        if (y & 1) 
            res = (res * x) % M; 
        y = (y >> 1) % M; 
        x = (x * x) % M; 
    } 
    return res; 
} 
  
// function to count the factors 
int countFactors(int n) 
{ 
    int count = 0; 
    for (int i = 1; i * i <= n; i++)  
    { 
        if (n % i == 0)  
        { 
  
            // If factors are equal, 
            // count only once 
            if (n / i == i) 
                count++; 
  
            // Otherwise count both 
            else
                count += 2; 
        } 
    } 
    return count; 
} 
  
long long multiplyFactors(int n) 
{ 
    int numFactor = countFactors(n); 
  
    // Calculate product of factors 
    long long product = power(n, numFactor / 2); 
  
    // If n is odd return 
    // power(n, numFactor/2) * sqrt(n) 
    if (numFactor%2==1) 
        product = (product * (int)sqrt(n)) % M; 
  
    return product; 
} 

bool comp(num_freq a, num_freq b){
    if(a.num!=b.num){
        return a.num>b.num;
    }
    else{
        return a.freq>b.freq;
    }
}

int binary_search(vector <num_freq> &G,vector <int> &cumulative_sum, int query){
    int i,lowerlim=0,upperlim=cumulative_sum.size()-1;
    while(1){
        i=(lowerlim+upperlim)/2;
        if(i<0 or i>=cumulative_sum.size()){
            return 0;
        }
        if(i==0){
            if(query<=cumulative_sum[i]){
                return G[i].num;
            }
        }
        else{
            if(query>cumulative_sum[i-1] && query<=cumulative_sum[i]){
                return G[i].num;
            }
            else if(query<cumulative_sum[i]){
                upperlim=i;
                continue;
            }
            else if(query>cumulative_sum[i]){
                lowerlim=i+1;
                continue;
            }
        }
    }
}


vector <int> Solve(vector <int> &A, vector <int> &B) {
    vector <num_freq> G;
    num_freq temp;
    vector <int> ans;
    int i,j,k;
    int f;
    for(i=0;i<A.size();i++){
        j=i;
        f=0;
        while(j<A.size()){
            if(A[j]<=A[i]){
                f++;
                j++;
            }
            else{
                break;
            }
        }
        j=i-1;
        while(j>=0){
            if(A[j]<=A[i]){
                f++;
                j--;
            }
            else{
                break;
            }
        }
        temp.num=multiplyFactors(A[i]);
        temp.freq=f;
        G.push_back(temp);
    }
    cout<<"Size of G:"<<G.size()<<endl;
    cout<<"printing G :"<<endl;
    for(i=0;i<G.size();i++){
        cout<<G[i].num<<" "<<G[i].freq<<endl;
    }
    sort(G.begin(),G.end(),comp);
    cout<<"printing G after sorting :"<<endl;
    for(i=0;i<G.size();i++){
        cout<<G[i].num<<" "<<G[i].freq<<endl;
    }
    vector <int> cumulative_sum;
    cumulative_sum.push_back(G[0].freq);
    for(i=1;i<G.size();i++){
        cumulative_sum.push_back(cumulative_sum[i-1]+G[i].freq);
    }
    cout<<"printing cumulative_sum: "<<endl;
    for(i=0;i<cumulative_sum.size();i++){
        cout<<cumulative_sum[i]<<endl;
    }
    cout<<"Handling queries:"<<endl;
    for(i=0;i<B.size();i++){
        cout<<"element "<<B[i]<<": "<<endl;
        cout<<binary_search(G,cumulative_sum,B[i]%cumulative_sum[cumulative_sum.size()-1])<<endl;
        ans.push_back(binary_search(G,cumulative_sum,B[i]%cumulative_sum[cumulative_sum.size()-1]));
    }
    return ans;
}


// Driver code 
int main() 
{ 
    cout<<multiplyFactors(8)<<endl;
     vector <int> A = {39, 99, 70, 24, 49, 13, 86, 43, 88, 74, 45, 92, 72, 71, 90, 32, 19, 76, 84, 46, 63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45 };
     vector <int> B = { 1221, 360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838 };
    //vector <int> A={1, 2, 4};
    //vector <int> B={1, 2, 3, 4, 5, 6};
    vector <int> ans= Solve(A,B);
    cout<<"Ans: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
} 
