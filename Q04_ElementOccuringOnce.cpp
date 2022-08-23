#include<bits/stdc++.h>
using namespace std;

int solve(vectpr<int>&v) {
    int r = 0;
    for(int i : v) r^=i;
    return r;
}

int main() {
    cout << solve({1,1,2,2,3,3,4,4,5,5,6});
}   