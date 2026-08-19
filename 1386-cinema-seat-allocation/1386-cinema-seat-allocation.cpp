using vi = vector<int>;
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        map<int,vi> mp;
        for (auto &v : a) {
            mp[v[0]].push_back(v[1]);
        }
        int ans = 2*n, sz = 11;
        for (auto &[k,v] : mp) {
            vi b(sz,0);
            for (auto x : v) b[x] = 1;
            for (int i=1; i<=9; i++) b[i] += b[i-1];
            auto f = [&] (int l, int r) {
                return b[r] - b[l-1];
            };
            if (f(2,9)) {
                if (!f(2,5) || !f(6,9) || !f(4,7)) ans--;
                else ans -= 2;
            }
        }
        return ans;
    }
};