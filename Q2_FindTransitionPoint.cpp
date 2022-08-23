#include<bits/stdc++.h>
using namespace std;

int solve(string str) {
    int l=0, h=str.size();
    while(l<h) {
        int mid = l + ((h-l)>>2);
        if(str[mid]=='1') h=mid;
        else l=mid+1;
    }
    return l;
}

int main() {
    string str = "11";
    cout << solve(str);
}