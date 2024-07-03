class Solution {
public:
    int minDifference(vector<int>& a) {
        int n = a.size();
        if (n <= 4) return 0;
        int ans = 2e9;
        sort(a.begin(), a.end());
        for (int i=0; i<4; i++) {
            int x = a[i];
            int y = a[n-4+i];
            ans = min(ans, abs(x-y));
        }
        return ans;
    }
};