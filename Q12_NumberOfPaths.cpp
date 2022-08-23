#include<bits/stdc++.h>
using namespace std;

int solve(int m, int n) {
    vector<int> dp(n, 0);
    dp[0]=1;
    for(int i=0; i<m; ++i) {
        for(int j=1; j<n; ++j) {
            dp[j]+=dp[j-1];
        }
    }
    return dp.back();
}

int main() {
    cout << solve(2,8);
}