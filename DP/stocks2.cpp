#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int maxProfit(const vector<int> &A) {
//Think like a Nub. On any two consecutive days when profit can be earned, just keep them.
   if(A.size()<=1){
       return 0;
   }
   int profit=0;
   for(int i=0;i<A.size()-1;i++){
       profit+=max(A[i+1]-A[i],0);
   }
   return profit;
}

int main(){
	vector <int> A={5, 2, 10};
	cout<<maxProfit(A)<<endl;
	return 0;
}
