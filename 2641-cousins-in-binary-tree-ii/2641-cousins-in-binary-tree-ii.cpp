const int sz = 1e5+1;

class Solution {
public:
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> mp(sz);
        
        function<void(TreeNode*,int)> f = [&] (TreeNode* v, int d) {
            if (!v) return;
            mp[d] += v->val;
            f(v->left,d+1); f(v->right,d+1);
        };
        f(root,0);
        
        function<void(TreeNode*, int, int)> g = [&] (TreeNode* v, int d, int s) {
            if (!v) return;
            v->val = mp[d] - s;
            int r = 0;
            if (v->left) r += v->left->val;
            if (v->right) r += v->right->val;
            if (v->left) g(v->left,d+1,r);
            if (v->right) g(v->right,d+1,r);
        };
        g(root, 0, root->val);
        
        return root;
    }
};