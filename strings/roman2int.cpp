#include <bits/stdc++.h>
using namespace std;

int romanToInt(string A) {
    vector <char> Roman={'M','D','C','L','X','V','I'};
    vector <int> val={1000,500,100,50,10,5,1};
	int sum=0;
	int i=0,j=i,k,l;
	while(i<A.size()){
		j=i;
		int neg=-1,count=0,current;
		while(j<A.size()){
			if(A[j]==A[i]){
				count++;
				j++;
				continue;
			}
			else{
				break;
			}
		}
		for(k=0;k<Roman.size();k++){
			if(Roman[k]==A[i]){
				current=count*val[k];
				break;
			}
		}
		if(j>=A.size()){
			sum+=current;
			return sum;
		}
		for(l=0;l<Roman.size();l++){
			if(Roman[l]==A[j]){
				if(val[l]>val[k]){
					current=-1*current;
					break;
				}
			}
		}
		sum+=current;
		i=j;
	}
	return sum;    
}

int main(){
	string A;
	cin>>A;
	cout<<romanToInt(A)<<endl;
	return 0;
}
