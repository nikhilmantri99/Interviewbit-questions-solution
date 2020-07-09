#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string print_binary(unsigned int x){
	string t;
	for(int i=0;i<32;i++){
		unsigned int temp= (x & ~(x-1));
		cout<<"temp:"<<temp<<endl;
		if(temp==0){
			t.push_back('0');
		}
		else{
			t.push_back('1');
		}
		x=x>>1;
	}
	string p;
	for(int i=0;i<t.size();i++){
		p=t[i]+p;
	}
	return p;
}

unsigned int reverse(unsigned int A) {
	unsigned int num = 0;
    int bits = 31;
    int i = 0;
    while(A){
        num = num + pow(2,31-i)*(A%2);
        A = A/2;
        i++;
    }
    return num;
}

int main(){
	int A;
	cin>>A;
	cout<<reverse(A)<<endl;
	return 0;
}