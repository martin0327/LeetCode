class Solution {
public:
    int minPairSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i=0; i<n/2; i++) {
            ans = max(ans, a[i]+a[n-1-i]);
        }
        return ans;
    }
};