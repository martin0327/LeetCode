using vs = vector<string>;
using vvs = vector<vs>;
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int mxd = 0;
        function<void(TreeNode*,int)> f = [&] (TreeNode* v, int d) {
            if (!v) return;
            f(v->left,d+1);
            f(v->right,d+1);
            mxd = max(mxd, d);
        };
        f(root,0);
        int n = mxd + 1, m = (1<<n) - 1;
        vvs ans(n, vs(m));
        function<void(TreeNode*,int,int)> g = [&] (TreeNode*v, int r, int c) {
            if (!v) return;
            ans[r][c] = to_string(v->val);
            int t = n-r-2;
            if (t >= 0) {
                g(v->left, r+1, c-(1<<t));
                g(v->right, r+1, c+(1<<t));
            }
        };
        g(root,0,(m-1)/2);
        return ans;
    }
};