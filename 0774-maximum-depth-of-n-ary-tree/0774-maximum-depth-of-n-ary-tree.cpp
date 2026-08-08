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
    int maxDepth(Node* root) {
        function<int(Node*,int)> f = [&]
        (Node* v, int d) {
            if (!v) return 0;
            int ret = d;
            for (auto u : v->children) {
                ret = max(ret,f(u,d+1));
            }
            return ret;
        };
        return f(root,1);
    }
};