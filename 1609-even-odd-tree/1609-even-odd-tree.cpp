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
    bool isEvenOddTree(TreeNode* root) {
        map<int,vector<int>> mp;
        function<void(TreeNode*, int)> f = [&] (TreeNode* u, int d) {
            if (!u) return;
            mp[d].push_back(u->val);
            f(u->left,d+1);
            f(u->right,d+1);
        };
        f(root,0);
        bool ans = true;
        for (auto [k,v] : mp) {
            int sz = v.size();
            for (int i=0; i<sz; i++) {
                if (k&1) {
                    ans &= (v[i] % 2 == 0);
                    if (i > 0) ans &= (v[i] < v[i-1]);
                }
                else {
                    ans &= (v[i] % 2 == 1);
                    if (i > 0) ans &= (v[i] > v[i-1]);
                }
            }
        }
        return ans;
    }
};