#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node{
	int length;
	unordered_set <int> uset;
}

//int solve(const vector<int> &A) {
int solve(const vector<int> &A) {
    int n = A.size();
    if(n <= 2) {
        return n;
    }

    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> pos;
    int max_len = 2;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int need = 2 * A[i] - A[j];
            if(pos.count(need)) {
                dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);
            }
            max_len = max(dp[i][j], max_len);
        }
        pos[A[i]] = i;
    }

    return max_len;
    
}
