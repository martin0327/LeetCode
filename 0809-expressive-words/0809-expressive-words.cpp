using pii = pair<int,int>;
using vp = vector<pii>;
class Solution {
public:
    int expressiveWords(string s, vector<string>& w) {
        auto f = [&] (string s) {
            vp a;
            for (auto c : s) {
                if (a.empty() || a.back().first != c) a.push_back({c,1});
                else a.back().second++;
            }
            return a;
        };
        auto g = [&] (vp &a, vp &b) {
            int n = a.size();
            if (n != b.size()) return false;
            for (int i=0; i<n; i++) {
                auto [x,c1] = a[i];
                auto [y,c2] = b[i];
                if (x != y) return false;
                if (c2 > c1) return false;
                if (c1 > c2 && c1 < 3) return false;
            }
            return true;
        };
        auto a = f(s);
        int ans = 0;
        for (auto t : w) {
            auto b = f(t);
            ans += g(a,b);
        }
        return ans;
    }
};