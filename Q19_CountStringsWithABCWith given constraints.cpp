#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int count=0;
    if(n>=1) {
        count+=1;
        count+=n;
        if(n>=2) {
            count+=(n-1)*n;
            count+=(n*(n-1))/2;
            if(n>=3) {
                count+=(n*(n-1)*(n-2))/2;
            }
        }
    }
    return count;
}

int main() {
    cout << solve(2);
}