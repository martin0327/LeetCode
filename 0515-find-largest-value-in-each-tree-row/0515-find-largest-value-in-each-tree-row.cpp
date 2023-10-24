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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        function<void(TreeNode*,int)> f = [&] (TreeNode* u, int d) {
            if (!u) return;
            if (ret.size()==d) ret.push_back(u->val);
            else ret[d] = max(ret[d], u->val);
            f(u->left, d+1);
            f(u->right, d+1);
        };
        f(root,0);
        return ret;
    }
};