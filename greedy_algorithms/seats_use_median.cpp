#include <bits/stdc++.h>
#include <iostream>

using namespace std;


void print_vec(vector <int> &A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

//distribute new seats around the median of the vector of the occupied seats. 

vector <int> generate_seats(vector <int> &pos){
    int n=pos.size();
    if(n%2==0){
        int mid=(pos[n/2-1]+pos[n/2])/2;
        int left=mid-n/2+1;
        int right=mid+n/2;
        vector <int> seats;
        for(int i=left;i<=right;i++){
            seats.push_back(i);
        }
        return seats;
    }
    else{
        int mid=pos[n/2];
        int left=mid-n/2;
        int right=mid+n/2;
        vector <int> seats;
        for(int i=left;i<=right;i++){
            seats.push_back(i);
        }
        return seats;
    }
}

int seats(string A) {
    vector <int> pos;
    int i;
    for(i=0;i<A.size();i++){
        if(A[i]=='x'){
            pos.push_back(i);
        }
    }
    if(pos.size()<=1 ){
        return 0;
    }
    //print_vec(pos);
    vector <int> seats=generate_seats(pos);
    //print_vec(seats);
    int m=10000003;
    int sum=0;
    for(i=0;i<pos.size();i++){
        sum+=abs(pos[i]-seats[i])%m;
        sum=sum%m;
    }
    return sum%m;
}

int main(){
    string A="....x..xx...x..";
    cout<<seats(A)<<endl;
    return 0;
}