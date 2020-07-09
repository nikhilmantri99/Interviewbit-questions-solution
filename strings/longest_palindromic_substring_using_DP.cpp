#include <bits/stdc++.h>
using namespace std;



// A common mistake:

// Some people will be tempted to come up with a quick solution, which is unfortunately flawed (however can be corrected easily):

//     Reverse S and become S’. Find the longest common substring between S and S’, which must also be the longest palindromic substring. 

// This seemed to work, let’s see some examples below.

// For example,

// S = “caba” 
// S’ = “abac”

// The longest common substring between S and S’ is “aba”, which is the answer.

// Let’s try another example:

// S = “abacdfgdcaba”
// S’ = “abacdgfdcaba”

// The longest common substring between S and S’ is “abacd”. Clearly, this is not a valid palindrome.

// We could see that the longest common substring method fails when there exists a reversed copy of a non-palindromic substring in some other part of S. To rectify this, each time we find a longest common substring candidate, we check if the substring’s indices are the same as the reversed substring’s original indices. If it is, then we attempt to update the longest palindrome found so far; if not, we skip this and find the next candidate.

// This gives us a O(N2) DP solution which uses O(N2) space (could be improved to use O(N) space). Please read more about Longest Common Substring here.

// Brute force solution, O(N3):
// The obvious brute force solution is to pick all possible starting and ending positions for a substring, and verify if it is a palindrome. There are a total of C(N, 2) such substrings (excluding the trivial solution where a character itself is a palindrome).

// Since verifying each substring takes O(N) time, the run time complexity is O(N3).

// Dynamic programming solution, O(N2) time and O(N2) space:
// To improve over the brute force solution from a DP approach, first think how we can avoid unnecessary re-computation in validating palindromes. Consider the case “ababa”. If we already knew that “bab” is a palindrome, it is obvious that “ababa” must be a palindrome since the two left and right end letters are the same.

// Stated more formally below:

// Define P[ i, j ] ← true iff the substring Si … Sj is a palindrome, otherwise false.

// Therefore,

// P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj )

// The base cases are:

// P[ i, i ] ← true
// P[ i, i+1 ] ← ( Si = Si+1 )

// This yields a straight forward DP solution, which we first initialize the one and two letters palindromes, and work our way up finding all three letters palindromes, and so on…

// Can you come up with a O(N^2) time complexity and O(1) space solution ?


string longestPalindrome(string A){
    vector <vector <bool>> DP(A.size(),vector <bool> (A.size(),false));
    int ans=0,len=1;
    int i,j,k;
    for(i=0;i<A.size();i++){
        int start=i,end=i;
        while(start>=0 && end<=A.size()){
            if(start==end){
                DP[start][end]=true;
            }
            else{
                DP[start][end]=(DP[start+1][end-1] && (A[start]==A[end]));
            }
            
            if(DP[start][end]==true && end-start+1>=len){
                if(end-start+1==len){
                    if(start<ans){
                        ans=start;
                    }
                }
                else{
                    ans=start;
                    len=end-start+1;
                }
            }
            start--;
            end++;
        }
    }
    
    for(i=0;i<A.size()-1;i++){
        int start=i,end=i+1;
        while(start>=0 && end<=A.size()){
            if(end-start==1 && A[start]==A[end]){
                DP[start][end]=true;
            }
            else{
                DP[start][end]=(DP[start+1][end-1] && (A[start]==A[end]));
            }
            
            if(DP[start][end]==true && end-start+1>=len){
                if(end-start+1==len){
                    if(start<ans){
                        ans=start;
                    }
                }
                else{
                    ans=start;
                    len=end-start+1;
                }
            }
            start--;
            end++;
        }
    }
    return A.substr(ans,len);
}
