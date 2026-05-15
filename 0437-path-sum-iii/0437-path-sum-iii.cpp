using ll = long long;
class Solution {
public:
    int pathSum(TreeNode* root, int tg) {
        map<ll,ll> mp; mp[0] = 1;
        ll cur = 0, ans = 0;
        function<void(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return;
            cur += u->val;
            if (mp.count(cur-tg)) ans += mp[cur-tg];
            mp[cur]++;
            f(u->left);
            f(u->right);
            if (--mp[cur] == 0) mp.erase(cur);
            cur -= u->val;
        };
        f(root);
        return ans;
    }
};