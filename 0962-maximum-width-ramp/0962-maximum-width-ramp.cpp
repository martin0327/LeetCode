class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        int n = a.size();
        vector<pair<int,int>> b(n);
        for (int i=0; i<n; i++) {
            b[i] = {a[i], i};
        }
        sort(b.begin(), b.end());
        int j = n+1;
        int ans = 0;
        for (auto [x,i] : b) {
            ans = max(ans, i-j);
            j = min(j, i);
        }
        return ans;
    }
};