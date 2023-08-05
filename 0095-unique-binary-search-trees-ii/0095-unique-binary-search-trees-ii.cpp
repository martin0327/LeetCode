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
using vi = vector<int>;
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vi a(n);
        iota(a.begin(), a.end(), 1);
        function<void(TreeNode*, int, vi&)> f = [&] (TreeNode* u, int x, vi &p) {
            if (!u) return;
            if (x < u->val) {
                if (!u->left) {
                    u->left = new TreeNode(x);
                    p[x] = u->val;
                    return;
                }
                else f(u->left,x,p);
            }
            else {
                if (!u->right) {
                    u->right = new TreeNode(x);
                    p[x] = u->val;
                    return;
                }
                else f(u->right,x,p);
            }
        };
        map<vi,TreeNode*> mp;
        do {
            vi p(n+1);
            TreeNode* u = new TreeNode(a.front());
            for (int i=1; i<n; i++) f(u,a[i],p);
            if (!mp.count(p)) mp[p] = u;
        } while(next_permutation(a.begin(), a.end()));
        vector<TreeNode*> ret;
        for (auto &[k,v] : mp) {
            ret.push_back(v);
        }
        return ret;
    }
};