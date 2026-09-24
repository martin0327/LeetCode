bool dp[17][1<<17];
int s[1<<17];
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n = a.size(), sz = 1<<n;
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        for (int mask=0; mask<sz; mask++) {
            for (int i=0; i<n; i++) {
                if (mask>>i&1) s[mask] += a[i];
            }
        }
        auto tot = s[sz-1];
        if (tot % k != 0) return false;

        tot /= k;
        for (int i=0; i<n; i++) {
            if (a[i] > tot) return false;
            dp[i][1<<i] = 1;
        }
        for (int mask=0; mask<sz; mask++) {
            for (int i=0; i<n; i++) {
                if (!dp[i][mask]) continue;
                if (mask == sz-1) return true;
                for (int j=0; j<n; j++) {
                    if (mask>>j&1) continue;
                    int nmask = mask | (1<<j);
                    int q1 = s[mask] / tot;
                    int q2 = s[nmask] / tot;
                    if (q1 == q2 || (s[mask] % tot == 0) || (s[nmask] % tot == 0)) {
                        dp[j][nmask] = 1;
                    }
                }
            }
        }
        return false;
    }
};