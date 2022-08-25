#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> stocks, int k) {
    if(stocks.size()==0) return 0;
    vector<vector<int>> dp(k+1, vector<int>(stocks.size(), 0));
    for(int i=1; i<=k; ++i) {
        for(int j=1; j<stocks.size(); ++j) {
            int maxval = INT_MIN;
            for(int t=0; t<j; ++t) {
                if(t==0) maxval = max(maxval, stocks[j]-stocks[t]);
                else maxval = max(maxval, stocks[j]-stocks[t]+dp[i-1][t-1]);
            }
            dp[i][j] = max(dp[i][j-1], maxval);
        }
    }
    return dp[k][stocks.size()-1];
}

int main() {
    cout << solve({10,22,5,75,65,80}, 2) << endl;
    cout << solve({20,580,420,900}, 3) << endl;
    cout << solve({100,90,80,50,25},1) << endl;
}