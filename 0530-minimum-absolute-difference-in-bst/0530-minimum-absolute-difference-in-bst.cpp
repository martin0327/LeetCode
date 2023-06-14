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
    int getMinimumDifference(TreeNode* root) {
        vector<int> a;
        function<void(TreeNode*)> f = [&](TreeNode* u) {
            if (!u) return;
            a.push_back(u->val);
            f(u->left);
            f(u->right);
        };
        f(root);
        sort(a.begin(), a.end());
        int ans = 1e9;
        for (int i=1; i<a.size(); i++) {
            ans = min(ans, a[i]-a[i-1]);
        }
        return ans;
    }
};