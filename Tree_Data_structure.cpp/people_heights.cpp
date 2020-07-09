#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node{
    int height;
    int infront_num;
};

bool comparefunc(node &a,node &b){
    return a.height<b.height;
}

struct brick{
    int val;
    bool operator < (const brick &t) const{
        return val>t.val;
    }
};

vector<int> order(vector<int> &A, vector<int> &B){
    //A->heights;
    //B->positions;
    vector <node> x;
    node temp;
    for(int i=0;i<A.size();i++){
        temp.height=A[i];
        temp.infront_num=B[i];
        x.push_back(temp);
    }
    sort(x.begin(),x.end(),comparefunc);
    for(int i=0;i<x.size();i++){
        cout<<x[i].height<<" ";
    }
    cout<<endl;
    vector <int> ans(A.size(), -1);
    priority_queue <brick> pos;
    brick b;
    for(int i=0;i<A.size();i++){
        b.val=i;
        pos.push(b);
    }
    for(int i=0;i<x.size();i++){
        cout<<"here"<<endl;
        stack <brick> t;
        cout<<"x[i].height: "<<x[i].height;
        cout<<" x[i].infront_num: "<<x[i].infront_num<<endl;
        for(int j=0;j<=x[i].infront_num;j++){
            t.push(pos.top());
            pos.pop();
        }
        cout<<"t.top().val: "<<t.top().val<<endl;
        ans[t.top().val]=x[i].height;
        t.pop();
        while(t.empty()==false){
            pos.push(t.top());
            t.pop();
        }
    }
    return ans;
}


//easier solution
vector<int> Solution::order(vector<int> &A, vector<int> &B){
    const vector<int>& heights = A;
    const vector<int>& in_front = B;
    
    map<int, int> height_map;
    int n = heights.size();
    for(int i = 0; i < n; i++) {
        height_map[heights[i]] = in_front[i];
    }
    vector<int> result(n, -1);
    for(auto& kv : height_map) {
        int count = -1, j;
        for(j = 0; j < n; j++) {
            if(result[j] == -1) {
                count++;
            }
            if(count == kv.second) {
                break;
            }
        }
        result[j] = kv.first;
    }

    return result;
}


int main(){
    vector <int> heights={1,2,3,4,5,6};
    vector <int> infronts={4,3,2,1,1,0};
    vector <int> ans=order(heights,infronts);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}