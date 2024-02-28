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
    int findBottomLeftValue(TreeNode* root) {
        map<int,vector<int>> mp;
        function<void(TreeNode*, int)> f = [&] (TreeNode* u, int d) {
            if (!u) return;
            mp[d].push_back(u->val);
            f(u->left,d+1);
            f(u->right,d+1);
        };
        f(root,0);
        int ans = prev(mp.end())->second.front();
        return ans;
    }
};