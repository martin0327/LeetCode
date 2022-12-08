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
    void f(TreeNode *node, vector<int> &a) {
        if (!node) return;
        if (!node->left && !node->right) a.push_back(node->val);
        f(node->left,a);
        f(node->right,a);
    }
    bool leafSimilar(TreeNode* x, TreeNode* y) {
        vector<int> a,b;
        f(x,a);
        f(y,b);
        return a==b;
    }
};