class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 1;
        function<int(TreeNode*)> f = [&] (TreeNode* v) {
            if (!v) return 0;
            int ret = 1, t = 1;
            auto l = v->left;
            auto r = v->right;
            if (l) {
                auto fl = f(l);
                if (v->val == l->val) {
                    ret = max(ret,fl+1);
                    t += fl;
                }
            }
            if (r) {
                auto fr = f(r);
                if (v->val == r->val) {
                    ret = max(ret,fr+1);
                    t += fr;
                }
            }
            ans = max(ans, t);
            return ret;
        };
        f(root);
        return ans-1;
    }
};