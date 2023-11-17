class Solution {
public:
    int minPairSum(vector<int>& a) {
        int n = a.size(), ans = 0;
        sort(a.begin(), a.end());
        for (int i=0; i<n/2; i++) {
            ans = max(ans, a[i]+a[n-1-i]);
        }
        return ans;
    }
};