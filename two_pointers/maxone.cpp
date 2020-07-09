#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

vector <int> construct_vector(int lower,int upper){
	vector <int> result;
	//cout<<"lower: "<<lower<<" upper: "<<upper<<endl;
	for(int i=lower;i<upper;i++){
		result.push_back(i);
	}
	print_vector(result);
	return result;
}

vector <int> zero_case(vector <int> &A){
	int i,j;
	i=0;
	int length_max=0;
	int checkpoint_1=0,checkpoint_2=0;
	int prev=-1;
	i=0;
	while(i<A.size()){
		if(A[i]==0){
			if(i-prev-1>length_max){
				length_max=i-prev-1;
				checkpoint_1=prev+1;
				checkpoint_2=i;
			}
			prev=i;
		}
		i++;	
	}
	if(i-prev-1>length_max){
		length_max=i-prev-1;
		checkpoint_1=prev+1;
		checkpoint_2=i;
	}
	//cout<<checkpoint_1<<" "<<checkpoint_2<<endl;
	return construct_vector(checkpoint_1,checkpoint_2);
}

vector <int> maxone(vector <int> &A, int B){
	print_vector(A);
	if(B==0){
		return zero_case(A);
	}
	int start,end,zero_count=0,length_max=0;
	int i,j,k;
	i=0;
	while(A[i]!=0 && i<A.size()){
		i++;
	}
	if(i==A.size()){
		return construct_vector(0,A.size());
	}
	start=i;
	while(i<A.size() && zero_count<B+1){
		if(A[i]==0) {
			zero_count++;
		}
		if(zero_count==B+1){
			break;
		}
		i++;
	}
	//cout<<"zero_count: "<<zero_count<<endl;
	if(i==A.size()){
		return construct_vector(0,A.size());
	}
	end=i;
	length_max=end;
	int checkpoint_1=0;
	int checkpoint_2=end;
	//cout<<"start: "<<start<<" end: "<<end<<endl;
	//end holds the position of a zero which is one more than the limit 
	// total chain of ones formed local_length=(start-prev_start)+(end-1-start)
	int local_length=0;
	i=start+1;
	while(i<A.size()){
		if(A[i]==0){
			int prev_start=start;
			start=i;
			j=end+1;
			while(j<A.size() && A[j]==1){
				j++;
			}
			//add condition here
			end=j;
			local_length=end-prev_start-1;
			if(local_length>length_max){
				length_max=local_length;
				checkpoint_1=prev_start+1;
				checkpoint_2=end;
			}
			if(end==A.size()){
				break;
			}
			i++;
		}
		else{
			i++;
		}
	}
	return construct_vector(checkpoint_1,checkpoint_2);
}

int main(){
	vector <int> A={0,1,1,1};
	int M=0;
	vector <int> result=maxone(A,M);
	return 0;
}