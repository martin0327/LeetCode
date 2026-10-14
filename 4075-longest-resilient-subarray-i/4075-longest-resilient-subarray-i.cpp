template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
using vi = vector<int>;
class Solution {
public:
    int resilientSubarray(vector<int>& a, int k) {
        int n = a.size(), ans = 1;
        for (auto &x : a) x = x % k;
        vi b(n,1);
        for (int i=1; i<n; i++) {
            if (a[i] == a[i-1]) b[i] = b[i-1] + 1;
            auto x = a[i], y = b[i]-1;
            x %= k;
            y %= k;
            if ((x*y) % k == 0) chmax(ans, b[i]);
        }
        return ans;
    }
};