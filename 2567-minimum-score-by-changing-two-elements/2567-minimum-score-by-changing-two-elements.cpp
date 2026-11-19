class Solution {
public:
    int minimizeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        if (n <= 3) return 0;
        int ans = a[n-3] - a[0];
        ans = min(ans, a[n-2] - a[1]);
        ans = min(ans, a[n-1] - a[2]);
        return ans;
    }
};