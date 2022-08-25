#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(string s, string t, int i=0, int j=0) {
    if(j>=t.size()) return 1;
    if(i>=s.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return dp[i][j] = solve(s, t, i+1, j+1) + solve(s, t, i+1, j);
    return dp[i][j] = solve(s, t, i+1, j);
}

int main() {
    int n=5;
    dp.assign(10000, vector<int>(10000, -1));
    cout << solve("banana", "ban") << endl;
    dp.assign(10000, vector<int>(10000, -1));
    cout << solve("geeksforgeeks", "ge") << endl;
}