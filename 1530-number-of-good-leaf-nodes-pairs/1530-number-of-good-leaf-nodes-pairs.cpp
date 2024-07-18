using vi = vector<int>;

class Solution {
public:
    int countPairs(TreeNode* root, int k) {
        int ans = 0;
        function<vi(TreeNode*)> f = [&] (TreeNode* v) {
            vi ret(k+1);
            if (!v) return ret;
            if (!v->left && !v->right) ret[1]++;

            auto l = f(v->left);
            auto r = f(v->right);
            for (int i=1; i<=k; i++) {
                for (int j=1; j<=k; j++) {
                    if (i+j<=k) {
                        ans += l[i] * r[j];
                    }
                }
            }
            for (int i=1; i<=k; i++) {
                if (i+1 <= k) {
                    ret[i+1] += l[i];
                    ret[i+1] += r[i];
                }
            }
            return ret;
        };
        f(root);
        return ans;
    }
};