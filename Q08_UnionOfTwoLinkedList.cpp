#include<bits/stdc++.h>
using namespace std;

class LLNode {
    public:
    int val;
    LLNode* next;
    LLNode(int val):val(val) {}
};

LLNode* createList(vector<int> v) {
    if(v.size()==0) return nullptr;
    LLNode* node = new LLNode(v[0]);
    LLNode* ans = node;
    for(int i=1; i<v.size(); i++) {
        node->next = new LLNode(v[i]);
        node=node->next;
    }
    return ans;
}

void print(LLNode* node) {
    while(node) {
        cout << node->val << " ";
        node=node->next;
    }
    cout << endl;
}

LLNode* solve(LLNode* node1, LLNode* node2) {
    LLNode* node3 = new LLNode(0);
    LLNode* ans = node3;
    set<int> st;
    while(node1) {
        st.insert(node1->val);
        node1=node1->next;
    }
    while(node2) {
        st.insert(node2->val);
        node2=node2->next;
    }
    for(int i : st) {
        node3->next = new LLNode(i);
        node3=node3->next;
    }
    return ans->next;
}

int main() {
    print(solve(createList({9,6,4,2,3,8}), createList({1,2,8,6,2})));
}