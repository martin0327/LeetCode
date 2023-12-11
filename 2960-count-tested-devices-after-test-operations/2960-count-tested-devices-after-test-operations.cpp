class Solution {
public:
    int countTestedDevices(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i]) {
                ans++;
                for (int j=i+1; j<n; j++) if (a[j]) a[j]--;
            }
        }
        return ans;
    }
};