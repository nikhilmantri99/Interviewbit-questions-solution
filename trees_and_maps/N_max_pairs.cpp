#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Instead of brute forcing through all the possible sum combinations we should find a way to limit our search space to possible candidate sum combinations.
// 1. Sort both arrays array A and array B.
// 2. Create a max heap i.e priority_queue in C++ to store the sum combinations along with the indices of elements from both arrays A and B which make up the sum. Heap is ordered by the sum.
// 3. Initialize the heap with the maximum possible sum combination i.e (A[N – 1] + B[N – 1] where N is the size of array) and with the indices of elements from both arrays (N – 1, N – 1). The tuple inside max heap will be (A[N-1] + B[N – 1], N – 1, N – 1). Heap is ordered by first value i.e sum of both elements.
// 4. Pop the heap to get the current largest sum and along with the indices of the element that make up the sum. Let the tuple be (sum, i, j).
// 4.1. Next insert (A[i – 1] + B[j], i – 1, j) and (A[i] + B[j – 1], i, j – 1) into the max heap but make sure that the pair of indices i.e (i – 1, j) and (i, j – 1) are not
// already present in the max heap. To check this we can use set in C++.
// 4.2 Go back to 4 until K times.


void print_vector(vector <int> &x){
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

vector<int> solve(vector<int> &A, vector<int> &B) {
    // sort both arrays A and B 
    sort(A.begin(), A.end()); 
    sort(B.begin(), B.end()); 
    vector <int> ans;
    int N = A.size(), K=A.size(); 
  
    // Max heap which contains tuple of the format 
    // (sum, (i, j)) i and j are the indices  
    // of the elements from array A 
    // and array B which make up the sum. 
    priority_queue<pair<int, pair<int, int> > > pq; 
  
    // my_set is used to store the indices of  
    // the  pair(i, j) we use my_set to make sure 
    // the indices doe not repeat inside max heap. 
    set<pair<int, int> > my_set; 
  
    // initialize the heap with the maximum sum 
    // combination ie (A[N - 1] + B[N - 1]) 
    // and also push indices (N - 1, N - 1) along  
    // with sum. 
    pq.push(make_pair(A[N - 1] + B[N - 1], 
                      make_pair(N-1, N-1))); 
  
    my_set.insert(make_pair(N - 1, N - 1)); 
  
    // iterate upto K 
    for (int count=0; count<K; count++) { 
  
        // tuple format (sum, (i, j)). 
        pair<int, pair<int, int> > temp = pq.top(); 
        pq.pop(); 
  
        ans.push_back(temp.first); 
  
        int i = temp.second.first; 
        int j = temp.second.second; 
  
        int sum = A[i - 1] + B[j]; 
  
        // insert (A[i - 1] + B[j], (i - 1, j))  
        // into max heap. 
        pair<int, int> temp1 = make_pair(i - 1, j); 
  
        // insert only if the pair (i - 1, j) is  
        // not already present inside the map i.e. 
        // no repeating pair should be present inside  
        // the heap. 
        if (my_set.find(temp1) == my_set.end()) { 
            pq.push(make_pair(sum, temp1)); 
            my_set.insert(temp1); 
        } 
  
        // insert (A[i] + B[j - 1], (i, j - 1))  
        // into max heap. 
        sum = A[i] + B[j - 1]; 
        temp1 = make_pair(i, j - 1); 
  
        // insert only if the pair (i, j - 1) 
        // is not present inside the heap. 
        if (my_set.find(temp1) == my_set.end()) { 
            pq.push(make_pair(sum, temp1)); 
            my_set.insert(temp1); 
        } 
    }
    return ans; 
}

int main(){
    vector <int> A={36, 27, -35, 43, -15, 36, 42, -1, -29, 12, -23, 40, 9, 13, -24, -10, -24, 22, -14, -39, 18, 17, -21, 32, -20, 12, -27, 17, -15, -21, -48, -28, 8, 19, 17, 43, 6, -39, -8, -21, 23, -29, -31, 34, -13, 48, -26, -35, 20, -37, -24, 41, 30, 6, 23, 12, 20, 46, 31, -45, -25, 34, -23, -14, -45, -4, -21, -37, 7, -26, 45, 32, -5, -36, 17, -16, 14, -7, 0, 37, -42, 26, 28};
    vector <int> B={38, 34, -47, 1, 4, 49, -18, 10, 26, 18, -11, -38, -24, 36, 44, -11, 45, 20, -16, 28, 17, -49, 47, -48, -33, 42, 2, 6, -49, 30, 36, -9, 15, 39, -6, -31, -10, -21, -19, -33, 47, 21, 31, 25, -41, -23, 17, 6, 47, 3, 36, 15, -44, 33, -31, -26, -22, 21, -18, -21, -47, -31, 20, 18, -42, -35, -10, -1, 46, -27, -32, -5, -4, 1, -29, 5, 29, 38, 14, -22, -9, 0, 43 };
    vector <int> ans=solve(A,B);
    cout<<"ans:"<<endl;
    print_vector(ans);
    return 0;
}