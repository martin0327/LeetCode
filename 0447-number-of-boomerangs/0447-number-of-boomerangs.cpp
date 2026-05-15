class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& a) {
        int n = a.size();
        auto sq = [&] (int x) { return x*x; };
        auto f = [&] (int i, int j) {
            int x1 = a[i][0], y1 = a[i][1];
            int x2 = a[j][0], y2 = a[j][1];
            return sq(x1-x2) + sq(y1-y2);
        };
        int ans = 0;
        for (int i=0; i<n; i++) {
            map<int,int> mp;
            for (int j=0; j<n; j++) {
                if (i == j) continue;
                mp[f(i,j)]++;
            }
            for (auto &[k,v] : mp) {
                ans += v*(v-1);
            }
        }
        return ans;
    }
};