    #include<bits/stdc++.h>
    using namespace std;

    int solve(vector<int>A, vector<int>B) {
        if(A.size()>B.size()) swap(A,B);
        for(int i=0;i<B.size(); ++i) {
            if(i==A.size() || A[i]!=B[i]) return i;
        }
        return -1;
    }

    int solver(vector<int> A, vector<int> B) {
        if(A.size()>B.size()) swap(A,B);
        int l=0, h=A.size()-1;
        while(l<h) {
            int mid = lo + ((h-l)>>1);
            if(A[mid]==B[mid]) l = mid+1;
            else h = mid;
        }
        return l;
    }

    int main() {
        cout << solver({1,2,3,4,5,6}, {1,2,3,3,4,5,6});
    }