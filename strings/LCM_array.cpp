#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);      
} 

int LCM(vector <int> &nums){
	int LCM=1;
	for(int i=0;i<nums.size();i++){
		LCM=LCM*nums[i]/gcd(LCM,nums[i]);
	}
	return LCM;
}

int main(){
	vector <int> temp={1,2,3,4,8};
	cout<<LCM(temp)<<endl;
	return 0;
}