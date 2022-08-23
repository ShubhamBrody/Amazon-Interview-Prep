#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k) {
    if(n==1) return 1;
    return (solve(n-1, k)+k-1)%n+1;
}

int main() {
    cout << solve(14,2);
}