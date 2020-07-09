#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <int> A={1,2,3,4,4,4,4,5,5,6,6,7};
	cout<<A.size()<<endl;
	cout<<upper_bound(A.begin(),A.end(),3)-A.begin()<<endl;
	return 0;
}