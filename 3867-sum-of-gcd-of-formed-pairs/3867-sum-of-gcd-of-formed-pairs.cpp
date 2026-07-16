using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    long long gcdSum(vector<int>& a) {
        ll n = a.size(), ans = 0;
        vi mx(n,a[0]), pre(n);
        for (int i=1; i<n; i++) {
            mx[i] = max(mx[i-1], (ll) a[i]);
        }
        for (int i=0; i<n; i++) {
            pre[i] = gcd(a[i], mx[i]);
        }
        sort(pre.begin(), pre.end());
        for (int i=0; i<n; i++) {
            int j = n-1-i;
            if (i >= j) break;
            ans += gcd(pre[i],pre[j]);
        }
        return ans;
    }
};