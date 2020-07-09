#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//Amazing Question. Definitely memorize it and be proud that u came up with the following solution using stacks.


struct wall{
	int height;
	int base_level;
	int max_tn;
};

void PrintStack(stack <int> s) 
{ 
    if (s.empty())  
        return; 
    int x = s.top();  
    s.pop(); 
    PrintStack(s);  
    cout << x << " "; 
    s.push(x); 
} 
void printstack(stack <int> &s){
	cout<<"contents of stack: (Bottom to top):"<<endl;
	PrintStack(s);
	cout<<endl;
}

void print_vector(vector <int> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void update_rainwater( stack <wall> &s, int incomingwall, int &rainwater ){
	if(s.top().max_tn==s.top().base_level || incomingwall==s.top().base_level){
		wall temp;
		temp.height=incomingwall;
		temp.base_level=incomingwall;
		temp.max_tn=max(incomingwall,s.top().max_tn);
		s.push(temp);
	}
	else{
		int width=0,h;
		int current_base=s.top().base_level;
		while(s.top().height==current_base){
			width++;
			s.pop();
		}
		if(s.top().height>current_base){
			h=min(s.top().height,incomingwall);
			rainwater+=max(((h-current_base)*width),0);
			wall temp;
			temp.height=h;
			temp.base_level=h;
			temp.max_tn=s.top().max_tn;
			for(int i=0;i<width;i++){
				s.push(temp);
			}
			update_rainwater(s,incomingwall,rainwater);
		}
	}
}

int trap(const vector<int> &A) {
    stack <wall> s;
    int i,rainwater=0;
    i=0;
    while(i<A.size() && A[i]==0){
    	i++;
    }
    if(i==A.size()){
    	return 0;
    }
    wall temp;
    temp.height=A[i];
    temp.base_level=A[i];
    temp.max_tn=A[i];
    s.push(temp);
    i++;
    while(i<A.size()){
    	if(A[i]<=s.top().base_level){
    		temp.base_level=A[i];
    		temp.max_tn=s.top().max_tn;
    		temp.height=A[i];
    		s.push(temp);
    	}
    	else if(A[i]>s.top().base_level){
    		update_rainwater(s,A[i],rainwater);
    	}
    	i++;
    }
    return rainwater;
}

int main(){
	vector <int> A={2, 0, 2};
	cout<<trap(A)<<endl;
	return 0;
}