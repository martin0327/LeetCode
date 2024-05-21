using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& a) {
        ll n = a.size(), m = to_string(a.front()).size();
        vvi b(m, vi(10));
        for (auto x : a) {
            for (int i=0; i<m; i++) {
                b[i][x%10]++;
                x /= 10;
            }
        }
        ll ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<10; j++) {
                ans += b[i][j] * (n-b[i][j]);
            }
        }
        return ans/2;
    }
};