class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        int dx = a[0][0] - a[1][0];
        int dy = a[0][1] - a[1][1];
        bool ans = true;
        int n = a.size();
        for (int i=2; i<n; i++) {
            int dx2 = a[0][0] - a[i][0];
            int dy2 = a[0][1] - a[i][1];
            if (dx*dy2 != dx2*dy) ans = false;
        }
        return ans;
    }
};