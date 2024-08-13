using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vvi dp[31][31];
    int check[31][31];
    vector<vector<int>> combinationSum2(vector<int>& a, int k) {
        vector<int> cnt(k+1);
        for (auto x : a) {
            if (x <= k) cnt[x]++;
        }
        
        function<vvi(int,int)> f = [&] (int i, int j) {
            vvi ret;
            if (j == 0) return dp[i][j] = ret = {{}};
            if (i > k || i > j) {
                return ret;
            }
            for (int x=0; x<=cnt[i]; x++) {
                auto vv = f(i+1,j-x*i);
                for (auto v : vv) {
                    int m = x;
                    while (m--) {
                        v.push_back(i);
                    }
                    ret.push_back(v);
                }
            }
            return dp[i][j] = ret;
        };
        
        vvi ret = f(0,k);
        return ret;
    }
};