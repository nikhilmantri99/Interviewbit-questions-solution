#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string convert(string A, int B) {
	int rows=B;
	vector <string> pattern(rows);
	int i=0,j=0,sign=1;
	if(rows==1){
		return A;
	}
	for(i=0;i<A.size();i++){
		pattern[j]+=A[i];
		if(j==rows-1){
			sign=-1;
		}
		if(j==0){
			sign=1;
		}
		if(sign==1){
			j++;
		}
		else if(sign==-1){
			j--;
		}
	}
	string combine;
	for(i=0;i<rows;i++){
		if(pattern[i].size()==0){
			break;
		}
		combine+=pattern[i];
	}
	return combine;
}

int main(){
	string X="kHAlbLzY8Dr4zR0eeLwvoRFg9r23Y3hEujEqdio0ctLh4jZ1izwLh70R7SAkFsXlZ8UlghCL95yezo5hBxQJ1Td6qFb3jpFrMj8pdvP6M6k7IaXkq21XhpmGNwl7tBe86eZasMW2BGhnqF6gPb1YjCTexgCurS";
	int n=1;
	// cin>>X;
	// cin>>n;
	string ans=convert(X,n);
	cout<<ans<<endl;
	return 0;
}