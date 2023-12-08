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
    string tree2str(TreeNode* root) {
        string ans;
        function<void(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return;
            string t = to_string(u->val);
            ans += t;
            if (!u->left && !u->right) return;
            if (!u->left) {
                ans += "()(";
                f(u->right);
                ans += ")";
            }
            else if (!u->right) {
                ans += '(';
                f(u->left);
                ans += ')';
            }
            else {
                ans += '(';
                f(u->left);
                ans += ')';
                ans += '(';
                f(u->right);
                ans += ')';
            }
        };
        f(root);
        return ans;
    }
};