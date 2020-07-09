#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int solve(vector <int> &A,int B,int C){
	if(A.size()==0) return 0;
	int n=C,countC=0,i,j,k;
	while(n>0){
		countC++;
		n=n/10;
	}
	if(countC>B){
		if(A[0]==0){
			if(B==1){
				return A.size();
			}
			return ((A.size()-1)*pow(A.size(),B-1));
		}
		else{
			return(pow(A.size(),B));
		}
	}
	else if(countC<B){
		return 0;
	}
	int ultimate;
	if(A[0]==0){
		ultimate=(A.size()-1)*pow(A.size(),B-1);
	}
	else{
		ultimate=(pow(A.size(),B));
	}
	if(B==1){
		ultimate=A.size();
	}
	cout<<"ultimate: "<<ultimate<<endl;
	int sum=0;
	int breakpoint;
	while(B>0){
		int digit=C/pow(10,B-1);
		C=C%((int)pow(10,B-1));
		cout<<"digit: "<<digit;
		i=0;
		breakpoint=0;
		if(B==1){
            while(i<A.size() && A[i]<digit){
                i++;
            }    
        }
        else{
			while(i<A.size() && A[i]<=digit){
				i++;
			}
		}
		if(A[i-1]<digit){
			breakpoint++;
		}
		int len=A.size()-i;
		cout<<" len: "<<len<<" multiplying_power: "<<pow(A.size(),B-1)<<endl;
		sum+=len*pow(A.size(),B-1);
		B--;
		if(breakpoint>0){
			break;
		}
	}
	return (ultimate-sum);
}

int main(){
	vector <int> X={1, 2, 4, 5, 6, 7, 9 };
	int B=5;
	int C=60837;
	cout<<solve(X,B,C)<<endl;
	return 0;
}