#include <bits/stdc++.h>
using namespace std;

void generate_primes(int n,vector <bool> &temp){
    temp[0]=false;
    temp[1]=false;
    int i,j;
    for(i=2;i<=sqrt(n);i++){
    	if(temp[i]==false){
    		continue;
    	}
        j=2*i;
        while(j<n+1){
            temp[j]=false;
            j=j+i;
        }
    }
    cout<<"All primes: ";
    for(i=0;i<temp.size();i++){
    	if(temp[i]==true) cout<<i<<" ";
    }
    cout<<endl;
}

vector<int> primesum(int A) {
    vector <bool> primes(A+1,true);
    generate_primes(A,primes);
    int i;
    vector <int> ans;
    for(i=2;i<primes.size();i++){
        if(primes[i]==true && primes[A-i]==true){
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
    }
}

int main(){
	int n;
	cin>>n;
	vector <int> Ans=primesum(n);
	int i;
	for(i=0;i<Ans.size();i++){
		cout<<Ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}