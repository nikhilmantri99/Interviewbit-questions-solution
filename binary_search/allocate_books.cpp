#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector <int> &A, int B,int val){
	int time_taken=0;
	int allocations=1;
	for(int i=0;i<A.size();i++){
		time_taken+=A[i];
		if(time_taken>=val){
			i=i-1;
			time_taken=0;
			allocations++;
			if(allocations>B){
				return false;
			}
		}
	}
	if(allocations>B) return false;
	return true;
}

int allocate_books(vector<int> &A, int B) {
    if(A.size()<B) return -1;
    int start=0,end=INT_MAX;
    int mid;
    while(start<=end){
    	mid=start+(end-start)/2;
    	if(isPossible(A,B,mid)==true){
    		end=mid-1;
    	}
    	else{
    		start=mid+1;
    	}
    }
    return start-1;
}

int main(){
	int students, n;
	cout<<"Enter number of students and books respectively: "<<endl;
	cin>>students>>n;
	cout<<"enter the number of pages one by one"<<endl;
	vector <int> books;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		books.push_back(temp);
	}
	cout<<allocate_books(books,students)<<endl;
	return 0;
}