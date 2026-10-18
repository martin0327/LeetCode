class Solution {
public:
    int minDeletions(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int i=1; i<n; i++) {
            if (a[i] == a[i-1]) ans++;
        }
        return ans;
    }
};