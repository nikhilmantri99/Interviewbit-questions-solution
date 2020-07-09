#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//just greedily turn on the current bulb and manage switch count to keep a track of what might have happened to others.

int manage_switch(int state, int switches_pressed){
    if(switches_pressed%2==0){
        return state;
    }
    else{
        if(state==0){
            return 1;
        }
        if(state==1){
            return 0;
        }
    }
}

int bulbs(vector<int> &A) {
    int i,switches_pressed=0;
    for(i=0;i<A.size();i++){
        A[i]=manage_switch(A[i],switches_pressed);
        if(A[i]==0){
            switches_pressed++;
            A[i]=1;
        }
    }
    return switches_pressed;
}

int main(){
	vector <int> A={0,0,0,1,0};
	cout<<bulbs(A)<<endl;
	return 0;
}