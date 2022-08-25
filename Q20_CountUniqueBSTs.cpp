#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(int n) {
    if(n<=1) return 1;
    int ans = 0;
    for(int i=1; i<=n; ++i) {
        dp[i-1] = dp[i-1] != -1 ? dp[i-1] : solve(i-1);
        dp[n-i] = dp[n-i] != -1 ? dp[n-i] : solve(n-i);
        ans+=dp[i-1]*dp[n-i];
    }
    return ans;
}

int main() {
    int n=3;
    dp.resize(n, -1);
    cout << solve(n);
}