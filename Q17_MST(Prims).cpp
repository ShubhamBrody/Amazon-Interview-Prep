#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> g, int V) {
    vector<int> key(V, INT_MAX), par(V, -1);
    set<pair<int,int>, greater<pair<int,int>>> pq;
    unordered_set<int> mstinc;
    int src=0;
    key[src]=0;
    pq.insert({0,src});
    while(!pq.empty()) {
        auto [val, u] = *pq.begin(); pq.erase(pq.begin());
        // cout << u << endl;
        if(mstinc.count(u)) continue;
        mstinc.insert(u);
        for(int v=0; v<V; ++v) {
            if(mstinc.count(v)==0 && key[v] > g[u][v]) {
                key[v] = g[u][v];
                pq.insert({key[v], v});
                par[v] = u;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<V; ++i) {
        if(par[i]!=-1)
        ans+=g[par[i]][i];
    }
    return ans;
}

int main() {
    vector<vector<int>> graph{ { 0, 2, 0, 6, 0 },
                            { 2, 0, 3, 8, 5 },
                            { 0, 3, 0, 0, 7 },
                            { 6, 8, 0, 0, 9 },
                            { 0, 5, 7, 9, 0 } };
    cout << solve(graph, graph.size());
    return 0;
}