//we can observe that product of factors will be n^(number of factor/2). 
//But when number of factor is odd (which means the number is perfect square) in that case product 
//will be n^(number of factor/2) * sqrt(n). We can count number of factors similar to approach above. 
//And we can calculate power efficiently using Modular Exponentiation
// C++ program to calculate product 
// of factors of number 
#include <bits/stdc++.h> 
#define M 1000000007 
using namespace std; 
  
// Iterative Function to calculate 
// (x^y) in O(log y) 
long long power(long long x, long long y) 
{ 
    long long res = 1; 
  
    while (y > 0)  
    { 
        if (y & 1) 
            res = (res * x) % M; 
        y = (y >> 1) % M; 
        x = (x * x) % M; 
    } 
    return res; 
} 
  
// function to count the factors 
int countFactors(int n) 
{ 
    int count = 0; 
    for (int i = 1; i * i <= n; i++)  
    { 
        if (n % i == 0)  
        { 
  
            // If factors are equal, 
            // count only once 
            if (n / i == i) 
                count++; 
  
            // Otherwise count both 
            else
                count += 2; 
        } 
    } 
    return count; 
} 
  
long long multiplyFactors(int n) 
{ 
    int numFactor = countFactors(n); 
  
    // Calculate product of factors 
    long long product = power(n, numFactor / 2); 
  
    // If n is odd return 
    // power(n, numFactor/2) * sqrt(n) 
    if (numFactor%2==1) 
        product = (product * (int)sqrt(n)) % M; 
  
    return product; 
} 
  
// Driver code 
int main() 
{ 
    int n ;
    cin>>n;
    cout << multiplyFactors(n) << endl; 
    return 0; 
} 
