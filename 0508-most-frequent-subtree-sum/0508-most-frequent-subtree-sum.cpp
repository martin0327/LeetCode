class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> mp;
        function<int(TreeNode*)> f = [&] (TreeNode* v) {
            if (!v) return 0;
            int s = v->val;
            s += f(v->left);
            s += f(v->right);
            mp[s]++;
            return s;
        };
        f(root);
        int mx = 0;
        for (auto &[k,v] : mp) {
            mx = max(mx, v);
        }
        vector<int> ans;
        for (auto &[k,v] : mp) {
            if (v == mx) ans.push_back(k);
        }
        return ans;
    }
};