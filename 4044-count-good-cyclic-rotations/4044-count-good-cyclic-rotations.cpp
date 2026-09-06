using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    int countGoodRotations(vector<int>& a) {
        ll n = a.size();
        vi b(a.begin(), a.end());
        for (int i=0; i<n; i++) b.push_back(a[i]);
        int m = b.size();
        vi pre(m+1); 
        for (int i=0; i<m; i++) {
            pre[i+1] = pre[i] + b[i];
        } 
        ll ans = 0, tot = pre[n];
        for (int i=0; i<n; i++) {
            auto x = pre[n/2+i] - pre[i];
            auto y = tot - x;
            if (x > y) ans++;
        }
        return ans;
    }
};