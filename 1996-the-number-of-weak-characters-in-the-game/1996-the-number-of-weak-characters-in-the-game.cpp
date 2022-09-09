class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        using pii = pair<int,int>;
        int n = p.size();
        vector<pii> a(n);
        for (int i=0; i<n; i++) {
            int x = p[i][0];
            int y = p[i][1];
            a[i] = {x,-y};
        }
        sort(a.rbegin(), a.rend());
        int cur = 0;
        int ans = 0;
        for (auto [x,y] : a) {
            y *= -1;
            if (cur > y) ans++;
            cur = max(cur, y);
        }
        return ans;
    }
};























