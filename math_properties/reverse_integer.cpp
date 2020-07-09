#include <bits/stdc++.h>
using namespace std;


int reverse1(int A) {
    int negative=0;
    if(abs(A)==(-1*A)){
        negative++;
    }
    long long int temp=0;
    A=abs(A);
    while(A!=0){
        temp=10*temp+A%10;
        A=A/10;
    }
    if (temp>INT_MAX || temp<INT_MIN){
        return 0;
    }
    if(negative==1){
        return (int)(-1*temp);
    }
    else{
        return (int)temp;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<reverse1(n)<<endl;
    return 0;
}
