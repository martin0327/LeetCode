class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int n = a.size(), ans = 1;
        for (int i=1,cur=1; i<n; i++) {
            if (a[i] > a[i-1]) cur++;
            else cur = 1;
            ans = max(ans, cur);
        }
        return ans;
    }
};