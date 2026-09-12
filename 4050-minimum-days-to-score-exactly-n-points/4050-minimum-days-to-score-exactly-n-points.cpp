template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using vi = vector<int>;
const int sz = 1e5+5, inf = 2e9;
vi b, dp;
class Solution {
public:
    int minDays(int n) {
        if (b.empty()) {
            b = {1};
            for (int i=2;;i++) {
                b.push_back(b.back() + i);
                if (b.back() > sz) break;
            }
            dp = vi(sz,inf);
            int m = b.size();
            for (int i=0; i<m; i++) {
                if (b[i] >= sz) break;
                dp[b[i]] = i+1;
            }
            for (int i=0; i<m; i++) {
                int x = b[i], cost = i+2;
                for (int j=1; j<sz; j++) {
                    int nj = j + x;
                    if (nj >= sz) continue;
                    chmin(dp[nj],dp[j]+cost);
                }
            }
        }
        return dp[n];
    }
};