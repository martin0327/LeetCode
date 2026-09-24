using vi = vector<int>;
using vvi = vector<vi>;
void chmin(int &x, int y) { x = min(x,y); }
const int sz = 26, inf = 2e9;
class Solution {
public:
    int minStickers(vector<string>& a, string t) {
        int n = t.size();
        sort(t.begin(), t.end());
        vvi b(sz);
        for (int i=0; i<n; i++) {
            b[t[i]-'a'].push_back(i);
        }
        vi dp(1<<n, inf);
        dp[0] = 0;
        for (auto &s : a) {
            for (int mask=0; mask<(1<<n); mask++) {
                if (dp[mask] == inf) continue;
                int nmask = mask;
                for (auto &ch : s) {
                    int x = ch - 'a';
                    for (auto j : b[x]) {
                        if (nmask>>j&1) continue;
                        nmask |= (1<<j);
                        break;
                    }
                }
                chmin(dp[nmask], dp[mask]+1);
            }
        }
        if (dp.back() == inf) return -1;
        return dp.back();
    }
};