#include <bits/stdc++.h>
#include <iostream>
using namespace std;


string int2roman(int x){
	int temp;
	temp=x;
	int n_digits=0;
	while(temp!=0){
		n_digits++;
		temp=temp/10;
	}
	//cout<<n_digits<<endl;
	temp=x;
	int current_digit;
	int i;
	string A;
	for(i=0;temp!=0;i++){
		if(i==0){
			current_digit=temp%10;
			if(current_digit==0) {
				temp=temp/10;
				continue;
			}
			if(current_digit>=1 && current_digit<=3){
				while(current_digit!=0){
					A="I"+A;
					current_digit--;
				}
				temp=temp/10;
				continue;
			}
			if(current_digit==4){
				A="IV"+A;
				temp=temp/10;
				continue;
			}
			if(current_digit>=5 && current_digit<=8){
				A="V"+A;
				current_digit=current_digit-5;
				while(current_digit!=0){
					A=A+"I";
					current_digit--;
				}
				temp=temp/10;
				continue;
			}
			if(current_digit==9){
				temp=temp/10;
				A="IX"+A;
				continue;
			}
		}
		if(i==1){
			string t;
			current_digit=temp%10;
			if(current_digit==0){
				temp=temp/10;
				continue;
			}
			if(current_digit>=1 && current_digit<=3){
				while(current_digit!=0){
					t="X"+t;
					current_digit--;
				}
				temp=temp/10;
				A=t+A;
				continue;
			}
			if(current_digit==4){
				t="XL"+t;
				temp=temp/10;
				A=t+A;
				continue;
			}
			if(current_digit>=5 && current_digit<=8){
				t="L"+t;
				current_digit=current_digit-5;
				while(current_digit!=0){
					t=t+"X";
					current_digit--;
				}
				A=t+A;
				temp=temp/10;
				continue;
			}
			if(current_digit==9){
				A="XC"+A;
				temp=temp/10;
				A=t+A;
				continue;
			}
		}
		if(i==2){
			string t;
			current_digit=temp%10;
			if(current_digit==0){ 
				temp=temp/10;
				continue;
			}
			if(current_digit>=1 && current_digit<=3){
				while(current_digit!=0){
					t="C"+t;
					current_digit--;
				}
				temp=temp/10;
				A=t+A;
				continue;
			}
			if(current_digit==4){
				t="CD"+t;
				temp=temp/10;
				A=t+A;
				continue;
			}
			if(current_digit>=5 && current_digit<=8){
				t="D"+t;
				current_digit=current_digit-5;
				while(current_digit!=0){
					t=t+"C";
					current_digit--;
				}
				A=t+A;
				temp=temp/10;
				continue;
			}
			if(current_digit==9){
				A="CM"+A;
				temp=temp/10;
				A=t+A;
				continue;
			}
		}
		if(i==3){
			current_digit=temp%10;
			if(current_digit==0) continue;
			if(current_digit>=1 && current_digit<=3){
				while(current_digit!=0){
					A="M"+A;
					current_digit--;
				}
				temp=temp/10;
				continue;
			}
		}
	}	
	return A;
}

int main(){
	int x;
	cin>>x;
	cout<<int2roman(x)<<endl;
	return 0;
}