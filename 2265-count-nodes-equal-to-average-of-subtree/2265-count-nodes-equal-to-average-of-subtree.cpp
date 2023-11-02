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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        function<pair<int,int>(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return make_pair(0,0);
            int s = u->val, c = 1;
            auto [s1, c1] = f(u->left);
            auto [s2, c2] = f(u->right);
            s += s1 + s2;
            c += c1 + c2;
            if (s/c == u->val) ans++;
            return make_pair(s,c);
        };
        f(root);
        return ans;        
    }
};