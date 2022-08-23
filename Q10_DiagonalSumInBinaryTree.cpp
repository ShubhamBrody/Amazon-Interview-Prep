#include<bits/stdc++.h>
using namespace std;

class Tree {
    public:
    int val;
    Tree *left, *right;
    Tree(int val, Tree* left=nullptr, Tree* right=nullptr):val(val),left(left),right(right) {}
};

unordered_map<int,int> mp;
void traversals(Tree* node, int lvl=0) {
    if(!node) return;
    mp[lvl]+=node->val;
    traversals(node->left, lvl+1);
    traversals(node->right, lvl);
}

int solve(Tree* node, int lvl=0) {
    mp.clear();
    traversals(node);
    int ans = 0;
    for(auto [a,b] : mp) ans = max(ans, b);
    return ans;
}


int main() {
    Tree* n1 = new Tree(1);
    Tree* n2 = new Tree(2);
    Tree* n3 = new Tree(3);
    Tree* n4 = new Tree(4);
    Tree* n5 = new Tree(5);
    Tree* n6 = new Tree(6);
    Tree* n7 = new Tree(7);
    Tree* n8 = new Tree(8);
    Tree* n9 = new Tree(9);
    Tree* n10 = new Tree(10);
    Tree* n11= new Tree(11);
    Tree* n12 = new Tree(12);
    n1->left = n2;
    n1->right = n3;
    n2->left = n9;
    n2->right = n6;
    n3->left = n4;
    n3->right = n5;
    n9->right = n10;
    n6->left = n11;
    n4->left = n12;
    n4->right = n7;
    
    cout << solve(n1) << endl;
    for(auto [a,b] : mp) cout << a << " " << b << endl;
}