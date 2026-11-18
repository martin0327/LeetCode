class Solution {
public:
    int numFriendRequests(vector<int>& a) {
        int n = a.size(), ans = 0;
        auto mx = *max_element(a.begin(), a.end());
        vector<int> cnt(mx+1);
        for (auto &x : a) cnt[x]++;
        for (auto x : a) {
            for (int y=0; y<=mx; y++) {
                if (2*(y-7) <= x) continue;
                if (y > x) continue;
                if (y > 100 && x < 100) continue;
                ans += cnt[y];
                if (x == y) ans--;
            }
        }
        return ans;
    }
};