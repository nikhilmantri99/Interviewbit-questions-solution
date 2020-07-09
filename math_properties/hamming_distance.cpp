#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
using namespace std;

#define M 1000000007

#define M 1000000007


//This function gives kth bit from the right (1<=k<=32) in binary representation. Its a bool value. So if >0, the bits is 1, else it is 0.
int giveKthBit(unsigned int n,unsigned int k) 
{ 
     return (n & (1 << (k-1))); 
} 
  
int hammingDistance(const vector <int> &A){
    int count_one,count_zero,sum=0;
    for(int j=0;j<32;j++){
        count_zero=0;
        count_one=0;
        for(int i=0;i<A.size();i++){
            int bit1=giveKthBit((unsigned int)A[i],(unsigned int)j+1);
            cout<<bit1<<" ";
            if(bit1>0){
                count_one++;
            }
            else{
                count_zero++;
            }
        }
        cout<<endl;
        sum+=((2*count_one*count_zero)%M);
        sum=sum%M;
    }
    return sum%M;
}

int main(){
	vector <int> A={2,4,6};
	cout<<hammingDistance(A)<<endl;
	return 0;
}