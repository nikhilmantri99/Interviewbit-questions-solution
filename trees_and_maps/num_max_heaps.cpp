//An amazing queation to learn dp and how to use it. Please go through the solution carefully and try to remember it.
//https://www.geeksforgeeks.org/number-ways-form-heap-n-distinct-integers/


// Since there is only one element as the root, 
//it must be the largest number. Now we have n-1 remaining elements. 
//The main observation here is that because of the max heap properties, 
//the structure of the heap nodes will remain the same in all instances, but only the values in the nodes will change.
// Assume there are l elements in the left sub-tree and r elements in the right sub-tree. Now for the root, l + r = n-1.
// From this we can see that we can choose any l of the remaining n-1 elements for the left sub-tree as they are all smaller than the root.
// We know the there are \binom{n-1}{l} ways to do this. 
//Next for each instance of these, we can have many heaps with l elements and for each of those we can have many heaps with r elements. Thus we can consider them as subproblems and recur for the final answer as:
// T(n) = \binom{n-1}{l} * T(L) * T(R).

// Now we have to find the values for l and r for a given n. We know that the height of the heap h = \log_2 n. Also the maximum number of elements that can be present in the h th level of any heap, m = 2^h, where the root is at the 0th level. Moreover the number of elements actually present in the last level of the heap p = n – (2^h – 1). (since 2^h - 1 number of nodes present till the penultimate level). Thus, there can be two cases: when the last level is more than or equal to half-filled:
// l = 2^h – 1, if p >= m / 2
// (or) the last level is less than half-filled:
// l = 2^h – 1 – ((m / 2) – p), if p < m / 2
// (we get 2^h– 1 here because left subtree has 2^0 + 2^1 +..+2^{h-1} nodes.
// From this we can also say that r = n – l – 1.

// We can use the dynamic programming approach discussed in this post here to find the values of \binom{n}{k}. Similarly if we look at the recursion tree for the optimal substructure recurrence formed above, we can see that it also has overlapping subproblems property, hence can be solved using dynamic programming:

//              T(7)
//             /    \
//           T(3)   T(3)
//          /  \     /  \    
//      T(1)  T(1) T(1) T(1) 

#include <bits/stdc++.h>
#include <iostream>

#include <cmath>

vector <vector <long long int>> nck(105,vector <long long int> (105,-1));
long long int M=1000000007;

long long int choose(int n, int k) 
{ 
    if (k > n) 
        return 0; 
    if (n <= 1) 
        return 1; 
    if (k == 0) 
        return 1; 
  
    if (nck[n][k] != -1) 
        return nck[n][k]; 
  
    long long int answer = (choose(n - 1, k - 1)%M + choose(n - 1, k)%M)%M; 
    nck[n][k] = answer%M; 
    return (answer%M); 
}

int left(int A){
    if(A<=1){
        return 0;
    }
    if(A==2){
        return 1;
    }
    int h=log2(A);
    //cout<<"A:"<<A<<" h:"<<h<<endl;
    int rem=A-((int)(pow(2,h)+0.5)-1);
    int l=((int)(pow(2,h-1)+0.5)-1)+min(rem,(int)(pow(2,h-1)+0.5));
    return l;
}

long long int return_num_trees(int A,vector <long long int> &dp){
    for(int i=3;i<=A;i++){
        int l=left(i);
        int r=(i-1)-l;
        //cout<<"i: "<<i<<" l: "<<l<<" r: "<<r<<endl;
        dp[i]=((choose(i-1,l)%M)*(dp[l]%M))%M;
        dp[i]=((dp[i]%M)*(dp[r]%M))%M;
    }
    return dp[A];
} 

int Solution::solve(int A) {
    if(A<=2){
        return 1;
    }
    vector <long long int> dp(105,-1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=1;
    return (int)return_num_trees(A,dp);
}
