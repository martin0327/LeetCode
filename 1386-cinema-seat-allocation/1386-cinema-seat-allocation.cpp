using vi = vector<int>;
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        map<int,vi> mp;
        for (auto &v : a) {
            mp[v[0]].push_back(v[1]);
        }
        int ans = 2*n;
        for (auto &[k,v] : mp) {
            vi b(11,1);
            for (auto x : v) b[x] = 0;
            for (int i=1; i<=9; i++) b[i] += b[i-1];
            auto f = [&] (int l, int r) {
                return b[r] - b[l-1];
            };
            if (f(2,9) < 8) {
                if (f(2,5) == 4 || f(6,9) == 4 || f(4,7) == 4) ans--;
                else ans -= 2;
            }
        }
        return ans;
    }
};