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
    void f(TreeNode* node, int d) {
        if (!node) return;
        mp[d].push_back(node->val);
        f(node->left, d+1);
        f(node->right, d+1);        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        f(root,0);
        vector<vector<int>> ret;
        for (auto &[k,v] : mp) {
            ret.push_back(v);
        }
        return ret;
    }
};