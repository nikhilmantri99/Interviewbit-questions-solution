#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

bool compare(int a, int b){
	vector <int> a_dig;
	vector <int> b_dig;
	int i,j,k,temp;
	while(a!=0){
		temp=a%10;
		a_dig.push_back(temp);
		a=a/10;
	}
	while(b!=0){
		temp=b%10;
		b_dig.push_back(temp);
		b=b/10;
	}
	i=a_dig.size()-1;
	j=b_dig.size()-1;
	while(1){
		//cout<<"comparing"<<a_dig[i]<<" "<<b_dig[j]<<endl;
		if(i==0 && j==0){
			if(a_dig[i]>b_dig[j]){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if (a_dig[i]>b_dig[j]){
				return true;
			}
			else if(a_dig[i]<b_dig[j]){
				return false;
			}
			else {
				if (i>0){
					i--;
				}
				else if(i==0)
				if (j>0){
					j--;
				}
			}
		}
	}

}

bool compare1(int a, int b){
	int a1=a;
	int b1=b;
	int lena=0,lenb=0;
	if(a1==0){
		lena++;
	}
	if(b1==0) lenb++;
	while(a1!=0){
		lena++;
		a1=a1/10;
	}
	while(b1!=0){
		lenb++;
		b1=b1/10;
	}
	if(lena<lenb){
		a=a*pow(10,lenb-lena);
		return a>b;
	}
	if(lenb<lena){
		b=b*pow(10,lena-lenb);
		return a>b;
	}
	if(lena==lenb){
		return a>b;
	}
}

//finally decided to go with the below function compare2. It simply compares if number 'a''b' is greater tha 'b''a',
//if yes , a before b in the number.	

bool compare2(int a,int b){
	int a1=a;
	int b1=b;
	int lena=0,lenb=0;
	if(a1==0){
		lena++;
	}
	if(b1==0) lenb++;
	while(a1!=0){
		lena++;
		a1=a1/10;
	}
	while(b1!=0){
		lenb++;
		b1=b1/10;
	}
	int ab=a*pow(10,lenb)+b;
	int ba=b*pow(10,lena)+a;
	return ab>ba;

}
string largest_number(vector <int> &A){
	string temp;
	sort(A.begin(),A.end(),compare2);
	for(int i=0;i<A.size();i++){
		temp=temp+to_string(A[i]);
	}
	return temp;
}

int main(){
	// int num1, num2;
	// cin>>num1>>num2;
	// bool ans=compare(num1,num2);
	// if(ans==true){
	// 	cout<<num1<<num2<<" is bigger than "<<num2<<num1<<endl;
	// }
	// else{
	// 	cout<<num2<<num1<<" is bigger than "<<num1<<num2<<endl;
	// }
	// return 0;
	vector <int> A;
	A.push_back(298);
	A.push_back(29);
	A.push_back(34);
	A.push_back(5);
	A.push_back(9);
	cout<<largest_number(A)<<endl;
	return 0;
}