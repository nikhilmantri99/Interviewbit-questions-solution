#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct box{
	int index1;
	int index2;
};

struct node{
	int value;
	int orig_index;
};

bool compare_fun(node &x,node &y){
	if(x.value!=y.value){
		return x.value<y.value;
	}
	else{
		return x.orig_index<y.orig_index;
	}
}

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int binary_search(vector <node> &x, int k,int orig_left,int left,int right){
	if(left>right){
		return -1;
	}
	int mid=(left+right)/2;
	if(x[mid].value==k){
		int i=mid;
		while(i>=orig_left && x[i].value==k){
			i--;
		}
		return i+1;
	}
	else if(x[mid].value>k){
		return binary_search(x,k,orig_left,left,mid-1);
	}
	else{
		return binary_search(x,k,orig_left,mid+1,right);
	}
}

vector<int> twoSum(vector<int> &A, int B) {
    print_vector(A);
    vector <node> x;
    int i;
    for(i=0;i<A.size();i++){
    	node t;
    	t.value=A[i];
    	t.orig_index=i;
    	x.push_back(t);
    }
    sort(x.begin(),x.end(),compare_fun);
    for(i=0;i<x.size();i++){
    	cout<<x[i].value<<" ";
    }
    cout<<endl;
    stack <box> s;
    for(i=0;i<x.size();i++){
    	int mid=binary_search(x,B-x[i].value,i+1,i+1,x.size()-1);
    	if(mid==-1) continue;
    	else{
    		cout<<x[i].value<<" "<<x[mid].value<<endl;
    		if(s.empty()){
    			box y;
    			y.index1=min(x[i].orig_index,x[mid].orig_index);
    			y.index2=max(x[i].orig_index,x[mid].orig_index);
    			s.push(y);
    		}
    		else{
    			if(s.top().index2>max(x[i].orig_index,x[mid].orig_index) || (s.top().index2==max(x[i].orig_index,x[mid].orig_index) && s.top().index1>min(x[i].orig_index,x[mid].orig_index))){
    				s.pop();
    				box y;
    				y.index1=min(x[i].orig_index,x[mid].orig_index);
    				y.index2=max(x[i].orig_index,x[mid].orig_index);
    				s.push(y);
    			}
    			else{
    				continue;
    			}
    		}
    	}
    }
    vector <int> ans;
    if(s.empty()) return ans;
    else{
    	ans.push_back(s.top().index1+1);
    	ans.push_back(s.top().index2+1);
    }
    return ans;
}

int main(){
	vector <int> A={4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 };
	int target=-3;
	vector <int> ans=twoSum(A,target);
	print_vector(ans);
	return 0;
}
