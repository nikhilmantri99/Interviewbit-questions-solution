#include <bits/stdc++.h>
using namespace std;
vector <int> getRow(int A) {
    int i,j,k;
    vector <int> current;
    for(i=0;i<=A;i++){
        vector <int> prev;
        cout<<"pushing these in prev:"<<endl;
        for(j=0;j<current.size();j++){
            cout<<" "<<current[j];
            prev.push_back(current[j]);
            //cout<<"here1"<<endl;
        }
        cout<<endl;
        if(i==0){
            current.push_back(1);
            //cout<<"here2"<<endl;
        }
        else if(i==1){
            current.push_back(1);
            //current.push_back(1);
            //cout<<"here3"<<endl;
        }
        else{
            cout<<"redefining current:\n";
            vector <int> current;
            current.push_back(1);
            for(j=0;j<prev.size()-1;j++){
                //cout<<"here4"<<endl;
                cout<<prev[j]+prev[j+1]<<" ";
                int val=prev[j]+prev[j+1];
                current.push_back(val);
            }
            cout<<endl;
            current.push_back(1);
        }
    }
    return current;
}

int main(){
    int n;
    cin>>n;
    vector <int> temp;
    temp=getRow(n);
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    return 0;
}