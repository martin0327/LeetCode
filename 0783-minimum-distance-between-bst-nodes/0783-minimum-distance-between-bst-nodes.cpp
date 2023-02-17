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
    void f(TreeNode *node) {
        if (!node) return;
        a.push_back(node->val);
        f(node->left);
        f(node->right);
    }
    int minDiffInBST(TreeNode* root) {
        f(root);
        sort(a.begin(), a.end());
        int ans = 1e9;
        for (int i=1; i<a.size(); i++) {
            ans = min(ans, abs(a[i]-a[i-1]));
        }
        return ans;
    }
};