#include <bits/stdc++.h>
using namespace std;

int cyclicity(int x,int d){
	int i=0;
	int temp=x%10,digit=1,count=1;
	//cout<<digit<<endl;
	while(temp%d!=1){
		//cout<<temp%d<<endl;
		count++;
		temp=(temp*x);
	}
	return count;
}

int remainder(int x,int n,int d){
	if(x==0) return 0;
	if(n==0) return 1;
	int cycle=cyclicity(x,d);
	n=n%cycle;
	if(n==0) return 1;
	//cout<<"n: "<<n<<" cycle: "<<cycle<<endl;
	int temp=x;
	int i=1,rem;
	while(i<=n){
		rem=temp%d;
		temp=temp*x;
		i++;
	}
	return (rem+d)%d;	
}

int recursive_function(int x,int n,int d){
	if(n==0) return ((1%d)+d)%d;
	else if (n==1) return (x%d+d)%d;

	if(n%2==0) return (((recursive_function(x%d,n/2,d)%d)*(recursive_function(x%d,n/2,d)%d))%d+d)%d;
	else if(n%2==1) return (((recursive_function(x%d,n/2,d)%d)*(recursive_function(x%d,n/2,d)%d)*(x%d))%d+d)%d;
}

int main(){
	int x,n,d;
	cin>>x>>n>>d;
	cout<<recursive_function(x,n,d)<<endl;
	return 0;
}