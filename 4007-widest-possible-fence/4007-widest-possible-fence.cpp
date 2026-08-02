template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
map<int,int> cnt;
map<int,int> res;
class Solution {
public:
    int maximumWidth(vector<int>& a) {
        cnt.clear();
        res.clear();
        for (auto x : a) cnt[x]++;
        for (auto [x1,c1] : cnt) {
            res[x1] += c1;
            for (auto [x2,c2] : cnt) {
                if (x1 > x2) continue;
                if (x1 == x2) res[x1+x2] += c1/2;
                else res[x1+x2] += min(c1,c2);
            }
        }
        int ans = 0;
        for (auto [k,v] : res) {
            chmax(ans,v);
        }
        return ans;
    }
};