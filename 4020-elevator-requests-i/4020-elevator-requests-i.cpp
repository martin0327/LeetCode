class Solution {
public:
    int elevatorRequests(int m, vector<int>& a) {
        int n = a.size(), ans = a[0];
        for (int i=1; i<n; i++) {
            ans += abs(a[i]-a[i-1]);
        }
        return ans;
    }
};