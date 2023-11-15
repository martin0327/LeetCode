class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] > ans) ans++;
        }
        return ans;
    }
};