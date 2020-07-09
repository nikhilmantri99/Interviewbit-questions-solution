#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;
#define M 2147483647

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int uniquePaths(int A, int B) {
    int a=max(A-1,B-1),b=min(A-1,B-1);
    A=a,B=b;
    int upper_product=1, lower_product=1 ;
    int i=A+B,j=B;
    while(i>A && j>0){
    	cout<<i<<" "<<j<<" "<<upper_product<<" "<<lower_product<<endl;
        upper_product=upper_product*i;
        lower_product=lower_product*j;
        int temp=gcd(upper_product,lower_product);
        upper_product=upper_product/temp;
        lower_product=lower_product/temp;
        i--;
        j--;
    }
    return upper_product;
}


int main(){
	int A=15;
	int B=9;
	cout<<uniquePaths(A,B)<<endl;
}