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
    vector<int> postorder(Node* root) {
        vector<int> ret;
        function<void(Node*)> f = [&] (Node* u) {
            if (!u) return;
            for (auto v : u->children) {
                f(v);
            }
            ret.push_back(u->val);
        };
        f(root);
        return ret;
    }
};