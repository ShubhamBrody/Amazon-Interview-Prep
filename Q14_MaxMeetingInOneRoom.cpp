#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> start, vector<int> end) {
    vector<pair<int,int>> v;
    for(int i=0; i<start.size(); ++i) {
        v.push_back({end[i], start[i]});
    }   
    sort(v.begin(), v.end());
    int ans = 1;
    int prev = 0;
    // cout << "0 ";
    for(int i=1; i<v.size(); ++i) {
        if(v[i].second>v[prev].first) {
            ++ans;
            // cout << i << " ";
            prev=i;
        }
    }
    // cout << endl;
    return ans;
}

int main() {
    cout << solve({1,3,0,5,8,5},{2,4,6,7,9,9}) << endl;
    cout << solve({75250,50074,43659,8931,11273,27545,50879,77924},{112960,114515,81825,93424,54316,35533,73383,160252});
}