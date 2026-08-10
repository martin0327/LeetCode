class Solution {
public:
    TreeNode* mergeTrees(TreeNode* u, TreeNode* v) {
        function<TreeNode*(TreeNode*,TreeNode*)> f = [&] (TreeNode* u, TreeNode* v) {
            if (!u && !v) return u;
            if (!v) return u;
            if (!u) return v;
            auto ret = new TreeNode(u->val + v->val);
            ret->left = f(u->left,v->left);
            ret->right = f(u->right,v->right);
            return ret;
        };
        return f(u,v);
    }
};