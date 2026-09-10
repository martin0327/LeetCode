class Solution {
public:
    int findShortestSubArray(vector<int>& a) {
        int n = a.size(), mx = 0;
        map<int,vector<int>> mp;
        for (int i=0; i<n; i++) {
            mp[a[i]].push_back(i);
        }
        for (auto &[k,v] : mp) {
            int sz = v.size();
            mx = max(mx, sz);
        }
        int ans = n;
        for (auto &[k,v] : mp) {
            int sz = v.size();
            if (mx == sz) {
                int t = v.back() - v.front() + 1;
                ans = min(ans, t);
            }
        }
        return ans;
    }
};