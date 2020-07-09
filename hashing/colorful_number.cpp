#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int lengthofA(int A){
	int n=0;
	while(A!=0){
		n++;
		A=A/10;
	}
	return n;
}

long int return_prod(int x){
	long int product=1;
	while(x!=0){
		product=product*(x%10);
		x=x/10;
	}
	return product;
}

int colorful(int A) {
	int i,j,k;
	unordered_map <long int,int> umap;
	long int product;
	int l=lengthofA(A);
	for(i=0;i<l;i++){
		int temp=A;
		int poweroften=pow(10,i+1);
		for(j=0;j<l-i;j++){
			product=return_prod(temp%poweroften);
			cout<<"current sequence: "<<temp%poweroften<<" product: "<<product<<endl;
			if(umap.find(product)==umap.end()){
				umap.insert(make_pair(product,1));
			}
			else{
				umap[product]++;
				return 0;
			}
			temp=temp/10;
		}
	}
	return 1;
}

int main(){
	int A=443;
	cout<<colorful(A)<<endl;
	return 0;
}
