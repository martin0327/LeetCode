const int mod = 1e9+7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hh, vector<int>& vv) {
        sort(hh.begin(), hh.end());
        sort(vv.begin(), vv.end());
        hh.push_back(h);
        vv.push_back(w);
        int n = hh.size();
        int m = vv.size();
        long long maxh = hh[0];
        for (int i=1; i<n; i++) {
            maxh = max(maxh, (long long) hh[i] - hh[i-1]);
        }
        long long maxv = vv[0];
        for (int i=1; i<m; i++) {
            maxv = max(maxv, (long long) vv[i] - vv[i-1]);
        }
        long long ans = maxh * maxv;
        ans %= mod;
        return ans;
    }
};