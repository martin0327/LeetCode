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
    int ans = 0;
    int f(TreeNode* v) {
        if (!v->left && !v->right) {
            ans += v->val;
            return 1;
        }
        int ret = 0;
        if (v->left) ret += 10 * f(v->left);
        if (v->right) ret += 10 * f(v->right);
        ans += ret * v->val;
        return ret;
    }
    int sumNumbers(TreeNode* v) {
        f(v);
        return ans;
    }
};