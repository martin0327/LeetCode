/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    map<int,vector<int>> mp;
    void f(Node* node, int d) {
        if (!node) return;
        mp[d].push_back(node->val);
        for (auto v : node->children) {
            f(v, d+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        f(root,0);
        vector<vector<int>> ret;
        for (auto &[k,v] : mp) {
            ret.push_back(v);
        }
        return ret;
    }
};