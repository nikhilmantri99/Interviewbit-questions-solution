#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long int divide1(long long int A, long long int B){
    if(A==0){
        return 0;
    }
    if(B==0){
        return INT_MAX;
    }
    if(A<B){
        return 0;
    }
    if(A==B){
        return 1;
    }
    long long int denom=B;
    long long int quotient=1;
    while(denom+denom<=A){
        denom=denom+denom;
        quotient=quotient+quotient;
    }
    return quotient+divide1(A-denom,B);
}

int divide(int A, int B) {
    int sign1=1,sign2=1;
    if(A<0){
        sign1=-1;
    }
    if(B<0){
        sign2=-1;
    }
    long long int x=(long long int)A;
    long long int y=(long long int)B;
    if(x<0){
        x=-x;
    }
    if(y<0){
        y=-y;
    }
    long long int ans=(int)divide1(x,y);
    if(ans==INT_MAX){
        return ans;
    }
    return sign1*sign2*(int)ans;
}

int main(){
    int A=2147483647,B=1;
    cout<<divide(A,B)<<endl;
    return 0;
}