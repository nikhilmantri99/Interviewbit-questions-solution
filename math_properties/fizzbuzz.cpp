#include <bits/stdc++.h>
using namespace std;

vector <string> fizzBuzz(int A) {
    vector <string> ans;
    string temp;
    for(int i=1;i<=A;i++){
        if(i%15==0){
            temp="FizzBuzz";
            ans.push_back(temp);
            continue;
        }
        if(i%3==0){
            temp="Fizz";
            ans.push_back(temp);
            continue;            
        }
        if(i%5==0){
            temp="Buzz";
            ans.push_back(temp);
            continue;
        }
        ans.push_back(to_string(i));
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector <string> ans= fizzBuzz(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}