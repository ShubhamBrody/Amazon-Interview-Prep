#include<bits/stdc++.h>
using namespace std;

int solve(vector<string> arrival, vector<string> depa) {
    unordered_map<int,int> mp;
    vector<pair<int,int>> slots;
    for(int i=0; i<depa.size(); ++i) {
        ++mp[stoi(arrival[i])];
        --mp[stoi(depa[i])+1];
    }
    for(auto p : mp) {
        slots.push_back(p);
    }
    sort(slots.begin(), slots.end());
    int ans=0, prev=0;
    for(int i=0; i<slots.size(); ++i) {
        slots[i].second+=prev;
        ans = max(ans, slots[i].second);
        prev = slots[i].second;
    }
    return ans;
} //line-sweep

int main() {
    cout << solve({"0900","0940","0950","1100","1500","1800"},{"0910","1200","1120","1130","1900","2000"}) << endl;
    cout << solve({"0900","0940"},{"0940","0949"}) << endl;
}