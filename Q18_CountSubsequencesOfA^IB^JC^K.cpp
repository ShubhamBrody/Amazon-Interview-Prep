#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    int a=0,b=0,c=0;
    for(char d : s) {
        if(d=='a') a=1+2*a;
        else if(d=='b') b=a+2*b;
        else if(d=='c') c=b+2*c;
    }
    return c;
}

int main() {
    cout << solve("abcabcabbbabc");
}