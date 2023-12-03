class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& a) {
        int n = a.size();
        int ans = 0;
        for (int i=1 ; i<n; i++) {
            int x1 = a[i][0], y1 = a[i][1];
            int x2 = a[i-1][0], y2 = a[i-1][1];
            int dx = abs(x1-x2), dy = abs(y1-y2);
            ans += min(dx,dy);
            ans += abs(dx-dy);
        }
        return ans;
    }
};