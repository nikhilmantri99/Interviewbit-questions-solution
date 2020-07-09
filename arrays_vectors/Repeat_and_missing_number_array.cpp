// You are given a read only array of n integers from 1 to n.
// Each integer appears exactly once except A which appears twice and B which is missing.
// Return A and B.
// Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
// Note that in your output A should precede B.
//use factorial and sum and use two variable two equation

#include <bits/stdc++.h> 
using namespace std; 
//solution type 1 uwing sum of squares and sum of numbers 

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int len = A.size(); 
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6; 
    long long int missingNumber=0, repeating=0; 
      
    for(int i=0;i<A.size(); i++){ 
       Sum_N -= (long long int)A[i]; 
       Sum_NSq -= (long long int)A[i]*(long long int)A[i]; 
    } 
      
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2; 
    repeating= missingNumber - Sum_N; 
    vector <int> ans; 
    ans.push_back(repeating); 
    ans.push_back(missingNumber); 
    return ans; 
}

void know_numbers(const vector<int> &A){
	long long int sum=0,k=1,n=1;
	int i;
	for(i=1;i<=A.size();i++){
		k=k*A[i-1];
		n=n*i;
		sum=sum+A[i-1];
	}
	long long int temp=(long long int)(A.size()*(A.size()+1)/2);
	cout<<sum<<" "<<temp<<" "<<k<<" "<<n<<endl;
	long long int y=n*(temp-sum)/(n-k);
	long long int x=y-(temp-sum);
	cout<<"repeated: "<<x<<" missing: "<<y<<endl;
}

int main(){
	vector <int> A;
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		int temp;
		cin>>temp;
		A.push_back(temp);
	}
	know_numbers(A);
	return 0;
}




