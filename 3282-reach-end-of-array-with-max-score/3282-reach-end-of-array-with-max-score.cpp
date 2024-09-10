using ll = long long;

class Solution {
public:
    long long findMaximumScore(vector<int>& a) {
        ll n = a.size();
        vector<ll> b(n, a.front());
        for (int i=1; i<n; i++) {
            b[i] = max((ll) a[i], b[i-1]);
        }
        return accumulate(b.begin(), b.end()-1, 0ll);
    }
};