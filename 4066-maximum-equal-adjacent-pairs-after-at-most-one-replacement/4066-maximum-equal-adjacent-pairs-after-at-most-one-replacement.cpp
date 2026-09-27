using pii = pair<int,int>;
class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& a) {
        map<pii,int> mp;
        int n = a.size(), ans = 0;
        for (int i=1; i<n; i++) {
            auto x = a[i-1], y = a[i];
            if (x > y) swap(x,y);
            mp[{x,y}]++;
        }
        for (auto [k,v] : mp) {
            auto [x,y] = k;
            if (x != y) ans = max(ans, v);
        }
        for (auto [k,v] : mp) {
            auto [x,y] = k;
            if (x == y) ans += v;
        }
        return ans;
    }
};