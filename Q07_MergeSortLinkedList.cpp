#include<bits/stdc++.h>
using namespace std;

// class Tree {
//     int val;
//     Tree *left, *right;
//     Tree(val, left=nullptr, right=nullptr) : val(val),left(left),right(right) {}
// };

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

LLNode* merge(LLNode* node1, LLNode* node2) {
    if(!node1) return node2;
    if(!node2) return node1;

    if(node1->val<=node2->val) {
        node1->next = merge(node1->next, node2);
        return node1;
    }
    node2->next = merge(node1, node2->next);
    return node2;
}

void findmid(LLNode* curr, LLNode** first, LLNode** second) {
    LLNode* slow=curr, *fast = curr->next;
    while(fast) {
        fast=fast->next;
        if(fast) {
            fast=fast->next;
            slow=slow->next;
        }
    }
    // while(fast || fast->next) {
    //     slow=slow->next;
    //     fast=fast->next->next;
    // }
    *first=curr;
    *second=slow->next;
    slow->next=nullptr;
}

void mergeSort(LLNode** head) {
    LLNode* c = *head;
    LLNode *first=nullptr, *second=nullptr;
    if(c==nullptr || c->next==nullptr) return;
    findmid(c, &first, &second);
    mergeSort(&first);
    mergeSort(&second);
    *head = merge(first, second);
}

LLNode* solve(LLNode* head) {
    mergeSort(&head);
    return head;
}

int main() {
    // print(createList({1,2,3}));
    print(solve(createList({1,4,1,3,5,6,3,3,6})));
}