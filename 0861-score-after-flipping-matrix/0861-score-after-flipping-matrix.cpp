class Solution {
public:
    int matrixScore(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), full = (1<<m) - 1;
        
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]) b[i] |= (1<<(m-1-j));
            }
        }
        auto c = b;
        for (int i=0; i<n; i++) {
            if (b[i]&(1<<(m-1))) b[i] ^= full;
            else c[i] ^= full;
        }

        auto f = [&] (vector<int> &a) {
            int ret = n * (1<<(m-1));
            for (int j=0; j<m-1; j++) {
                int cnt = 0;
                for (auto &x : a) cnt += (x>>j&1);
                cnt = max(cnt, n-cnt);
                ret += cnt * (1<<j);
            }
            return ret;
        };
        
        return max(f(b), f(c));
    }
};