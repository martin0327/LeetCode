using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    vector<int> countTasks(vector<int>& aa, vector<int>& bb) {
        vi a(aa.begin(), aa.end());
        vi b(bb.begin(), bb.end());
        ll n = a.size(), m = b.size();
        vi pre(n+1);
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i-1];
        }
        vector<int> ans(m);
        ll pos = 0, rem = 0;
        for (int i=0; i<m; i++) {
            auto x = b[i] + rem;
            auto it = upper_bound(pre.begin(), pre.end(), x+pre[pos]);
            if (it == pre.begin()) {
                assert(false);
            }
            else {
                int j = it - pre.begin() - 1;
                rem = x - (pre[j] - pre[pos]);
                pos = j;
                ans[i] = n - pos;
                if (pos == n) {
                    pos = 0, rem = 0;
                }
            }
        }
        return ans;
    }
};