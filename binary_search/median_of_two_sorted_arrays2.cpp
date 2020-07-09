#include <bits/stdc++.h>
using namespace std;

double median_single_array(const vector <int> &t){
    if(t.size()%2==1){
        return (double)t[t.size()/2];
    }
    else{
        return ((double)t[t.size()/2]+(double)t[(t.size()/2)-1])/2.0;
    }
}

double median_excluding_corner_cases(const vector <int> &x,const vector <int> &y){
    int partitionX,partitionY,ix,iy,start,end,len_left,len_right;
    start=0;
    end=x.size()-1;
    len_left=(x.size()+y.size()+1)/2;
    while(start<=end){
        //cout<<"here"<<endl;
        cout<<"start: "<<start<<" end:"<<end<<endl;
        ix=start+(end-start)/2;
        iy=len_left-ix-2;
        cout<<"ix: "<<ix<<" iy: "<<iy<<endl;
        int xix,xixp1,yiy,yiyp1;
        if(ix<0){
            cout<<"negation"<<endl;
            xix=INT_MIN;
        }
        else{
            xix=x[ix];
        }
        
        if(iy<0){
            yiy=INT_MIN;
        }
        else{
            yiy=y[iy];
        }
        if(ix==x.size()-1){
            xixp1=INT_MAX;
        }
        else{
            xixp1=x[ix+1];
        }
        yiy=y[iy];
        if(iy==y.size()-1){
            yiyp1=INT_MAX;
        }
        else{
            yiyp1=y[iy+1];
        }
        
        cout<<"xix: "<<xix<<" yiy: "<<yiy;
        cout<<" xixp1: "<<xixp1<<" yiyp1: "<<yiyp1<<endl;
        if(xix<=yiyp1+1 && yiy<=xixp1){
            //found;
            if((x.size()+y.size())%2==1){
                return (double)max(xix,yiy);
            }
            else{
                double t1=max(xix,yiy);
                double t2=min(xixp1,yiyp1);
                return (t1+t2)/2.0;
            }
            break;
        }
        else if(xix>yiyp1){
            end=ix-1;
        }
        else{
            start=ix+1;
        }
    }
    if(end<start){
        if(start==0){
            int n=x.size()+y.size();
            int i=n/2;
            if(n%2==1){
                return y[i];
            }
            else{
                return ((double)y[i]+(double)y[i-1])/2.0;
            }
        }
        if(end==x.size()-1){
            int n=x.size()+y.size();
            int i=n/2-x.size();
            if(n%2==1){
                return y[i];
            }
            else{
                return ((double)y[i]+(double)y[i-1])/2.0;
            }
        }
    }
}

double median(const vector <int> &x,const vector <int> &y){//x small, y large
    if(x.size()==0){
        return median_single_array(y); 
    }
    else if(y.size()==0){
        return median_single_array(x);
    }
    else if(x.size()+y.size()<=4){
        vector <int> t;
        for(int i=0;i<x.size();i++){
            t.push_back(x[i]);
        }
        for(int i=0;i<y.size();i++){
            t.push_back(y[i]);
        }
        sort(t.begin(),t.end());
        return median_single_array(t);
    }
    else if(x[x.size()-1]<=y[0]){
        int n=x.size()+y.size();
        int i=n/2-x.size();
        if(n%2==1){
            return y[i];
        }
        else{
            return ((double)y[i]+(double)y[i-1])/2.0;
        }
    }
    else if(y[y.size()-1]<=x[0]){
        int n=x.size()+y.size();
        int i=n/2;
        if(n%2==1){
            return y[i];
        }
        else{
            return ((double)y[i]+(double)y[i-1])/2.0;
        }
    }
    else{
        if(x.size()==1){
            vector <int> temp;
            temp.push_back(INT_MIN);
            temp.push_back(x[0]);
            temp.push_back(INT_MAX);
            return median_excluding_corner_cases(temp,y);
        }
        return median_excluding_corner_cases(x,y);
    }
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    if(A.size()<=B.size()){
        return median(A,B);
    }
    else{
        return median(B,A);
    }
}

int main(){
    vector <int> A = {16, 19 };
    vector <int> B ={-46, -15, -9, -7, -2, 24, 40};
    cout<<findMedianSortedArrays(A,B)<<endl;
    return 0;
}

