class Solution {
public:
    int countGroups(vector<int>& a, vector<int>& b, int d) {
        int n = a.size(), cnt = 0;
        for (int i=n-1; i>0; i--) {
            if (b[i] < b[i-1] || a[i]-a[i-1] <= d) {
                cnt++;
                b[i-1] = b[i];
            }
        }
        int ans = n - cnt;
        return ans;
    }
};