#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//We first sort the array based on the arrival timings. Then we maintain a priority queue that onctains the bookings
//Always, the booking qith the least departure time is maintained at the top. Thus we can now easily keep popping from the queue
// the bookings that have lesse departure than the new arrival time.
//Keep checking queue size at every iteration and thus it will help us to return . 
struct booking{
    int arrival;
    int departure;
    bool operator<(const booking &rhs)const{
        return departure>rhs.departure;
    }
};

struct Book{
    int arr;
    int dep;
};

bool comparefunc(Book &x, Book &y){
    if(x.arr!=y.arr){
        return x.arr<y.arr;
    }
    else{
        return x.dep<y.dep;
    }
}

void print_vec(vector <Book> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].arr<<" "<<vec[i].dep<<endl;
    }
    cout<<endl;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector <Book> vec;
    int i,j,k;
    for(i=0;i<arrive.size();i++){
        Book temp;
        temp.arr=arrive[i];
        temp.dep=depart[i];
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end(),comparefunc);
    //print_vec(vec);
    priority_queue <booking> pq;
    for(i=0;i<vec.size();i++){
        if(vec[i].arr==vec[i].dep){
            continue;
        }
        // cout<<"new booking: "<<vec[i].arr<<" "<<vec[i].dep<<endl;
        // if(pq.empty()==false){
        //     cout<<"At the top: ";
        //     cout<<pq.top().arrival<<" "<<pq.top().departure<<endl;
        // }
        //cout<<"removing the bookings: "<<endl;
        while(pq.empty()==false && pq.top().departure<=vec[i].arr){
            //cout<<pq.top().arrival<<" "<<pq.top().departure<<endl;
            pq.pop();
        }
        if(pq.size()>=K){
            //cout<<pq.size()<<" greater than "<<K<<endl;
            return false;
        }
        booking t;
        t.arrival=vec[i].arr;
        t.departure=vec[i].dep;
        pq.push(t);
    }
    return true;
}