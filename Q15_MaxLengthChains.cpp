#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> v) {
    if(v.size()==0) return 0;
    vector<pair<int,int>> sets;
    for(int i=1; i<v.size(); i+=2) {
        sets.push_back({v[i-1], v[i]});
    }
    sort(sets.begin(), sets.end());
    queue<pair<int,int>> q;
    q.push({0,1});
    int ans = 1;
    while(!q.empty()) {
        auto [idx, len] = q.front(); q.pop();
        auto newidx = upper_bound(sets.begin(), sets.end(), make_pair(sets[idx].second, INT_MAX))-sets.begin(); 
        if(newidx==sets.size()) {
            ans = max(ans, len);
        } else {
            q.push({newidx, len+1});
        }
    }
    return ans;
}

int main() {
    cout << solve({5,24,39,60,15,28,27,40,50,90}) << endl;
    cout << solve({5,10,1,11}) << endl;
}