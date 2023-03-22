class Solution {
public:
    int findPoisonedDuration(vector<int>& a, int d) {
        int ans = d, n = a.size();
        for (int i=1; i<n; i++) {
            ans += min(a[i]-a[i-1],d);
        }        
        return ans;
    }
};