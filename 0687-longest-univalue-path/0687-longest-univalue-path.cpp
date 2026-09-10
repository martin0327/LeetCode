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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 1;
        function<int(TreeNode*)> f = [&] (TreeNode* v) {
            if (!v) return 0;
            int ret = 1, t = 1;
            auto L = v->left;
            auto R = v->right;
            if (L) {
                auto fl = f(L);
                if (v->val == L->val) {
                    ret = max(ret,fl+1);
                    t += fl;
                }
            }
            if (R) {
                auto fr = f(R);
                if (v->val == R->val) {
                    ret = max(ret,fr+1);
                    t += fr;
                }
            }
            // cout << v->val << " " << t << endl;
            ans = max(ans, t);
            return ret;
        };
        f(root);
        return ans-1;
    }
};