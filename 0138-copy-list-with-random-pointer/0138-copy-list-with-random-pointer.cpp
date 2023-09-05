/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        map<Node*,int> node2idx;
        map<int,Node*> idx2node;
        Node* cur = head;
        int idx = 0;
        while (cur) {
            node2idx[cur] = idx;
            idx2node[idx++] = cur;
            cur = cur->next;
        }
        int n = idx;
        
        map<int,int> rand_idx;
        for (int i=0; i<n; i++) {
            Node* cur = idx2node[i];
            if (cur->random) rand_idx[i] = node2idx[cur->random];
            else rand_idx[i]= -1;
        }
        
        vector<Node*> a;
        for (int i=0; i<n; i++) {
            Node* cur = new Node(idx2node[i]->val);
            a.push_back(cur);
        }
        for (int i=0; i<n; i++) {
            if (rand_idx[i] != -1) a[i]->random = a[rand_idx[i]];
        }
        for (int i=0; i<n-1; i++) {
            a[i]->next = a[i+1];
        }
        
        
        return a[0];
    }
};