#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    if(n<=1) return n;
    int l=1, h=n;
    while(l<h) {
        int mid = l + ((h-l)>>1);
        int temp = mid*mid;
        if(temp < n) l=mid+1;
        else if(temp==n) return mid;
        else h=mid;
    }
    return l-1;
}

int solve_anotherway(int n) {
    long long x = n;
    while(x*x > n) x = (x + n/x)/2;
    return x;
}

int main() {
    int n = 10;
    cout << solve(n);
    cout << solve_anotherway(n);
}