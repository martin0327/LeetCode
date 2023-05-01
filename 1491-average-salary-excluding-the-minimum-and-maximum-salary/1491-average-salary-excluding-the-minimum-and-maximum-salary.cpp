class Solution {
public:
    double average(vector<int>& a) {
        double n = a.size();
        int mx = 0, mn = 1e9, s = 0;
        for (auto x : a) {
            mx = max(x,mx);
            mn = min(x,mn);
            s += x;
        }
        double ans = (s-mx-mn) / (n-2);
        return ans;
    }
};