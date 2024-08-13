using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vvi dp[31][31];
    int check[31][31];
    vector<vector<int>> combinationSum2(vector<int>& a, int tg) {
        vector<int> cnt(tg+1);
        for (auto x : a) {
            if (x <= tg) cnt[x]++;
        }
        function<vvi(int,int)> f = [&] (int i, int j) {
            vvi ret;
            if (j == 0) return dp[i][j] = ret = {{}};
            if (i > tg || i > j) {
                return ret;
            }
            for (int x=0; x<=cnt[i]; x++) {
                auto vv = f(i+1,j-x*i);
                for (auto p : vv) {
                    int mul = x;
                    while (mul--) {
                        p.push_back(i);
                    }
                    ret.push_back(p);
                }
            }
            return dp[i][j] = ret;
        };

        vvi ret = f(0,tg);
        return ret;
    }
};