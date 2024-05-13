class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int full = (1<<m) - 1;
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) b[i] |= (1<<(m-1-j));
            }
        }
        auto c = b;

        for (auto &x : b) {
            if ((x&(1<<(m-1))) == 0) x ^= full;
        }
        for (auto &x : c) {
            if (x&(1<<(m-1))) x ^= full;
        }
        // debug(b);
        // debug(c);
        int ans1 = n * (1<<(m-1)), ans2 = ans1;

        auto f = [&] (int &ans, vector<int> &a) {
            for (int j=0; j<m-1; j++) {
                int cnt = 0;
                for (auto x : a) cnt += (x>>j&1);
                cnt = max(cnt, n-cnt);
                // debug(j,cnt);
                ans += cnt * (1<<j);
            }
        };
        f(ans1,b);
        f(ans2,c);
        return max(ans1,ans2);
    }
};