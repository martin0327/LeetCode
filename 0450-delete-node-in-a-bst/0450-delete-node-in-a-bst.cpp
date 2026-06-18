using vi = vector<int>;
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vi a;
        function<void(TreeNode*)> f = [&] (TreeNode* v) {
            if (!v) return;
            f(v->left);
            if (v->val != key) a.push_back(v->val);
            f(v->right);
        };
        f(root);

        int n = a.size();
        if (n == 0) return nullptr;
        function<void(TreeNode*,int,int)> g = [&] (TreeNode* v, int l, int r) {
            int m = (l+r)/2;
            v->val = a[m];
            if (l <= m-1) {
                v->left = new TreeNode();
                g(v->left,l,m-1);
            }
            if (m+1 <= r) {
                v->right = new TreeNode();
                g(v->right,m+1,r);
            }
        };
        auto ret = new TreeNode();
        g(ret,0,n-1);
        return ret;
    }
};