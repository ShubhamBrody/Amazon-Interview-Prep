#include<bits/stdc++.h>
using namespace std;

void sortins(stack<int> &stk, int x) {
    if(stk.empty() or stk.top()<=x) stk.push(x);
    else {
        int t = stk.top(); stk.pop();
        sortins(stk, x);
        stk.push(t);
    }
}

void solve(stack<int> &stk) {
    if(!stk.empty()) {
        int x = stk.top(); stk.pop();
        solve(stk);
        sortins(stk, x);
    }
}

int main() {
    stack<int> stk;
    stk.push(5);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    solve(stk);
    while(!stk.empty()) {
        cout << stk.top() << endl; stk.pop();
    }
}