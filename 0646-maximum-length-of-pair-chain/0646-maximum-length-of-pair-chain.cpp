class Solution {
public:
    int findLongestChain(vector<vector<int>>& a) {
        int ans = 0;
        vector<pair<int,int>> b;
        for (auto v : a) {
            b.push_back({v[1],v[0]});
        }
        sort(b.begin(),b.end());
        int y = -1e9;
        for (auto [r,l] : b) {
            if (l > y) {
                ans++;
                y = r;
            }
        }
        return ans;
    }
};