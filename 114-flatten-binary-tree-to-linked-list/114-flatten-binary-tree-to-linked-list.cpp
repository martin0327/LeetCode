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
    vector<int> a;
    void f(TreeNode* node) {
        if (!node) return;
        a.push_back(node->val);
        f(node->left);
        f(node->right);
        node->left = nullptr;
        node->right = nullptr;
    }
    void flatten(TreeNode* root) {
        f(root);
        for (int i=0; i<a.size(); i++) {
            root->val = a[i];
            if (i==a.size()-1) break;
            root->right = new TreeNode();
            root = root->right;
        }
    }
};