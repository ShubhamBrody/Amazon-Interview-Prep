#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v, int l, int h) {
    int x = v[h], i=l;
    for(int j=l; j<h; ++j) {
        if(v[j]<=x) {
            swap(v[j], v[i++]);
        }
    }
    swap(v[i], v[h]);
    return i;
}

int solve(vector<int> &v, int l, int h, int k) {
    if(k>0 && k<=h-l+1) {
        int pos = partition(v, l, h);
        if(pos-l==k-1) return v[pos];
        if(pos-l>k-1) return solve(v, l, pos-1, k);
        return solve(v, pos+1, h, k-pos+l-1);
    }
    return INT_MAX;
}

int main() {
    vector<int> v{7,10,4,3,20,15};
    int k = 3, l = 0, h = v.size()-1;
    cout << solve(v, l, h, k); // Kth Smallest
    cout << solve(v, l, h, v.size()-k+1); // Kth Largest
}