#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// We can solve this problem using BFS, every node of the implicit graph will be a binary digit number and 
//if the number is x, then its next level node will be x0 and x1 (x concatenated with 0 and 1).
// In starting we will push 1 into our queue, which will push 10 and 11 into queue later and so on, 
//after taking number from queue we’ll check whether this number is multiple of given number or not, if 
//yes then return this number as result, this will be our final result because BFS proceeds level by level so 
//the first answer we got will be our smallest answer also.
// In the below code binary digit number is treated as a string, because for some number it can be very 
//large and can outside the limit of even long long, mod operation on number stored as the string is also implemented.
// The main optimization tweak of code is using a set for modular value, if a string with the same mod 
//value has previously occurred we won’t push this new string into our queue. Reason for not pushing new string 
//is explained below,
// Let x and y be strings, which gives the 
//same modular value. Let x be the smaller one. 
//let z be another string which when appended to y gives us a number divisible by N. 
//If so, then we can also append this string to x, which is smaller than y, and still get a 
//number divisible by n. So we can safely ignore y, as the smallest result will be obtained via x only.

int mod(string &t, int N) 
{ 
    int r = 0; 
    for (int i = 0; i < t.length(); i++) 
    { 
        r = r * 10 + (t[i] - '0'); 
        r %= N; 
    } 
    return r; 
} 

string multiple(int A) {
	 if(A==0){
        return "0";
    }
    if(A==1){
        return "1";
    }
	queue <string> q;
	set<int> visit;
	string t="1";
	q.push(t);
	while(q.empty()==false){
		  // Take the front number from queue. 
        t = q.front();      
        q.pop(); 
  
        // Find remainder of t with respect to N. 
        int rem = mod(t, A); 
  
        // if remainder is 0 then we have 
        // found our solution 
        if (rem == 0) 
            return t; 
  
        // If this remainder is not previously seen, 
        // then push t0 and t1 in our queue 
        else if(visit.find(rem) == visit.end()) 
        { 
            visit.insert(rem); 
            q.push(t + "0"); 
            q.push(t + "1"); 
        } 
	}
	return t;
}


int main(){
	int N;
	cin>>N;
	cout<<multiple(N)<<endl;
	return 0;
}
