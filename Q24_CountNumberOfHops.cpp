#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(int n) {
    if(n<3) return 1;
    int a=1, b=1, c=2;
    for(int i=3; i<=n; ++i) {
        int d = c+b+a;
        a=b;
        b=c;
        c=d;
    }
    return c;
}

int main() {
    int n=5;
    cout << solve(n) << endl;
}