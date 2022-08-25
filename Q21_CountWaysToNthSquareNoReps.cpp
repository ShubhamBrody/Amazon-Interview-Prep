#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int ans = 0;
    // for(int i=0; i*2<=n; ++i) {
    //     int k=1, r=1, t=n-i;
    //     for(int j=0; j<i; ++j) {
    //         k*=(n-i-j);
    //         r*=(j+1);
    //     }
    //     cout << k/r << endl;
    //     ans += k/r;
    // }
    // return ans;
    
    for(int i=0; i*2<=n; ++i) {
        ++ans;
    }
    return ans;
    
    // vector<int> dp(n+1, 0);
    // dp[1]=1, dp[2]=2;
    // for(int i=3; i<=n; ++i) {
    //     dp[i] = dp[i-1]+dp[i-2];
    // }
    // return dp[n];
}

int main() {
    int n=5;
    cout << solve(n);
}