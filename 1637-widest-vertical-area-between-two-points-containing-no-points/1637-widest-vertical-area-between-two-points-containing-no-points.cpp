class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& pt) {
        vector<int> a;
        for (auto xy : pt) a.push_back(xy[0]);
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = 0;
        for (int i=1; i<n; i++) ans = max(ans, a[i]-a[i-1]);
        return ans;
    }
};