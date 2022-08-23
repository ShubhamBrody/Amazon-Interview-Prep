#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v) { 
    for(int i : v) cout << i << " ";
    cout << endl;
}

vector<int> solve(vector<vector<int>> arr, int k) {
    set<pair<int,int>> st;
    for(int i=0; i<k; ++i) {
        st.insert({arr[i][0],i});
    }
    vector<int> turn(k, 0);
    vector<int> ans;
    while(!st.empty()) {
        auto [num, idx] = *st.begin();
        st.erase(st.begin());
        ans.push_back(num);
        if(turn[idx]<k-1) {
            st.insert({arr[idx][++turn[idx]], idx});
        }
    }
    return ans;
}

int main() {
    print(solve({{1,2,3,4,5}, {2,5,8,3,7}, {1,6,7,9,10}, {4,6,7,10,12}, {5,13,14,15,16}}, 5));
}