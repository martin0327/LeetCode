/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_set<int> s;
    bool ret = false;
    int t;
    
    void f(TreeNode *node) {
        if (!node) return;
        if (s.count(t-node->val)) ret = true;
        s.insert(node->val);
        f(node->left);
        f(node->right);
    }
    bool findTarget(TreeNode* root, int k) {
        t = k;
        f(root);
        return ret;
    }
}; 