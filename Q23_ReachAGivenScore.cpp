#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(int n) {
    vector<int> dp(n, 0);
    dp[0]=1;
    vector<int>coins{3,5,10};
    for(int i : coins) for(int j=i; j<=n; ++j) dp[j]+=dp[j-i];
    return dp[n];
}

int main() {
    int n=13;
    cout << solve(n) << endl;
}