#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 

void print_interval(vector <Interval> &x){
	cout<<"printing interval:"<<endl;
	int i;
	for(i=0;i<x.size();i++){
		cout<<x[i].start<<" "<<x[i].end<<endl;
	}
}

vector <Interval> Insert(vector<Interval> &intervals, Interval newInterval) {
	if(newInterval.end<newInterval.start){
		int y=newInterval.start;
		newInterval.start=newInterval.end;
		newInterval.end=y;
	}
    int left_index=-1,right_index=-1,i;
    Interval temp;
    vector <Interval> ans;
    for(i=0;i<intervals.size();i++){
    	if(intervals[i].end<newInterval.start){
    	    cout<<"here0"<<endl;
    	    ans.push_back(intervals[i]);
    	}
    	else{
    		cout<<"here0_else"<<endl;
    		break;
    	}
    }
    if(i==intervals.size()){
    	cout<<"here1"<<endl;
        ans.push_back(newInterval);
        return ans;
    }
    if(i<intervals.size() && intervals[i].start>newInterval.end){
        cout<<"here2"<<endl;
        ans.push_back(newInterval);
        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
    if(i<intervals.size() && intervals[i].start>newInterval.start){
    	temp.start=newInterval.start;
    	while(i<intervals.size()){
    		if(newInterval.end>=intervals[i].end){
    			i++;
    		}
    		else{
    			break;
    		}
    	}
    	if(i==intervals.size()){
    		cout<<"here7"<<endl;
    		temp.end=newInterval.end;
    		ans.push_back(temp);
    		return ans;
    	}
    	else{
    		if(intervals[i].start>newInterval.end){
    			cout<<"here8"<<endl;
    			temp.end=newInterval.end;
    			ans.push_back(temp);
    			while(i<intervals.size()){
    				ans.push_back(intervals[i]);
    				i++;
    			}
    			return ans;
    		}
    		else if(intervals[i].start==newInterval.end){
    			cout<<"here9"<<endl;
    			temp.end=intervals[i].end;
    			ans.push_back(temp);
    			i++;
    			while(i<intervals.size()){
    				ans.push_back(intervals[i]);
    				i++;
    			}
    			return ans;
    		}
    		else if(intervals[i].start<newInterval.end){
    			cout<<"here10"<<endl;
    			temp.end=intervals[i].end;
    			ans.push_back(temp);
    			i++;
    			while(i<intervals.size()){
    				ans.push_back(intervals[i]);
    				i++;
    			}
    			return ans;
    		}
    	}
    }
    if(i<intervals.size() && intervals[i].start<=newInterval.start){
    	cout<<"here3"<<endl;
    	if(intervals[i].start<newInterval.start){
    		cout<<"here4"<<endl;
    		temp.start=intervals[i].start;
    	}
    	else{
    		cout<<"here5"<<endl;
    		//Interval temp;
    		temp.start=newInterval.start;
    	}
    	while(i<intervals.size()){
    		if(newInterval.end>=intervals[i].end){
    			i++;
    		}
    		else{
    			break;
    		}
    	}
    	if(i==intervals.size()){
    		cout<<"here7"<<endl;
    		temp.end=newInterval.end;
    		ans.push_back(temp);
    		return ans;
    	}
    	else{
    		if(intervals[i].start>newInterval.end){
    			cout<<"here8"<<endl;
    			temp.end=newInterval.end;
    			ans.push_back(temp);
    			while(i<intervals.size()){
    				ans.push_back(intervals[i]);
    				i++;
    			}
    			return ans;
    		}
    		else if(intervals[i].start==newInterval.end){
    			cout<<"here9"<<endl;
    			temp.end=intervals[i].end;
    			ans.push_back(temp);
    			i++;
    			while(i<intervals.size()){
    				ans.push_back(intervals[i]);
    				i++;
    			}
    			return ans;
    		}
    		else if(intervals[i].start<newInterval.end){
    			cout<<"here10"<<endl;
    			temp.end=intervals[i].end;
    			ans.push_back(temp);
    			i++;
    			while(i<intervals.size()){
    				ans.push_back(intervals[i]);
    				i++;
    			}
    			return ans;
    		}
    	}
    }   
}

int main(){
	vector <Interval> intervals;
	Interval temp;
	temp.start=3;temp.end=5;intervals.push_back(temp);
	temp.start=8;temp.end=10;intervals.push_back(temp);
	// temp.start=;temp.end=7;intervals.push_back(temp);
	// temp.start=8;temp.end=10;intervals.push_back(temp);
	// temp.start=12;temp.end=16;intervals.push_back(temp);
	cout<<"before merging:"<<endl;
	print_interval(intervals);
	temp.start=1;temp.end=12;
	cout<<"merging with: "<<temp.start<<" "<<temp.end<<endl;
	vector <Interval> ans=Insert(intervals,temp);
	cout<<"post_merging:"<<endl;
	print_interval(ans);
	return 0;
}