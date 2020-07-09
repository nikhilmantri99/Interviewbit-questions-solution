#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct person{
    int height;
    int taller_peeps;
};

bool compare_func(person &a, person &b){
    if(a.height!=b.height){
        return a.height<b.height;
    }
    return a.taller_peeps<b.taller_peeps;
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    //A->heights, B->infronts;
    vector <int> ans(A.size(),-1);
    vector <person> people;
    person temp;
    int i,j,k;
    for(i=0;i<A.size();i++){
        temp.height=A[i];
        temp.taller_peeps=B[i];
        people.push_back(temp);
    }
    sort(people.begin(),people.end(),compare_func);
    //cout<<"here"<<endl;
    for(i=0;i<people.size();i++){
        j=0;
        while(j<ans.size() && ans[j]!=-1){
            j++;
        }
        int mark=0;
        while(mark<people[i].taller_peeps){
            if(ans[j]!=-1){
                j++;
                continue;
            }
            j++;
            mark++;
        }
        while(j<ans.size() && ans[j]!=-1){
            j++;
        }
        ans[j]=people[i].height;
    }
    return ans;
}
