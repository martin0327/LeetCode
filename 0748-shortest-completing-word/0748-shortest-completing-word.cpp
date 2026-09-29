using vi = vector<int>;
class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& a) {
        int sz = 26;
        auto f = [&] (string s) {
            vi cnt(sz);
            for (auto &ch : s) {
                int x = ch - 'a';
                int y = ch - 'A';
                if (0 <= x && x < sz) cnt[x]++;
                else if (0 <= y && y < sz) cnt[y]++;
            }
            return cnt;
        };
        auto tg = f(s);
        auto g = [&] (vi &a, vi &b) {
            for (int i=0; i<sz; i++) {
                if (a[i] > b[i]) return false;
            }
            return true;
        };
        vector<tuple<int,int,string>> res;
        for (int i=0; i<a.size(); i++) {
            auto t = a[i];
            int sz = t.size();
            auto cnt = f(t);
            if (g(tg,cnt)) {
                res.push_back({sz,i,t});
            }
        }
        auto [len,idx,ans] = *min_element(res.begin(), res.end());
        return ans;
    }
};