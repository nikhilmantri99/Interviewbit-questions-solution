#include <bits/stdc++.h>
using namespace std;

int books(vector<int> &A, int B) {
    int i,j,k,low=0,high=INT_MAX,mid,sum,optimal_solution=INT_MAX;
    while(low<=high){
        mid=low+(high-low)/2;
        cout<<"low: "<<low<<" high:"<<high<<" mid: "<<mid<<endl;
        i=0,j=0,sum=0;
        for(i=0;i<A.size();){
            sum=0;
            while(i<A.size() && sum+A[i]<=mid){
                sum=sum+A[i];
                i++;
            }
            j++;
            cout<<"sum: "<<sum<<" j: "<<j<<endl;    
            if(j>B){
                break;
            }
        }
        if(j==B){
            int maxsum=INT_MIN;
            cout<<"here"<<endl;
            sum=0;
            j=0;
            for(i=0;i<A.size();){
                sum=0;
                while(i<A.size() && sum+A[i]<=mid){
                    sum=sum+A[i];
                    i++;
                }
                cout<<"sum: "<<sum<<" j: "<<j<<endl;
                maxsum=max(sum,maxsum);
                j++;
                if(j>B){
                    break;
                }
            }
            optimal_solution=min(optimal_solution,maxsum);
            if(high==maxsum){
                break;
            }
            high=maxsum;
            continue;
        }
        else if(j<B){
            optimal_solution=min(optimal_solution,mid);
            high=mid-1;
        }
        else if(j>B){
            low=mid+1;
        }
    }
    if(optimal_solution!=INT_MAX){
        return optimal_solution;
    }
    return -1;
}

int main(){
    vector <int> A={97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24 };
    int B=26;
    cout<<books(A,B)<<endl;
    return 0;
}