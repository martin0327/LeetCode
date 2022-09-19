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
    map<int,vector<int>> mp;
    void f(TreeNode *node, int d) {
        if (!node) return;
        if (d&1) mp[d].push_back(node->val);
        f(node->left,d+1);
        f(node->right,d+1);
    }
    void g(TreeNode *node, int d) {
        if (!node) return;
        if (d&1) {
            node->val = mp[d].back();
            mp[d].pop_back();
        }
        g(node->left,d+1);
        g(node->right,d+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        f(root,0);
        g(root,0);
        return root;
    }
}; 