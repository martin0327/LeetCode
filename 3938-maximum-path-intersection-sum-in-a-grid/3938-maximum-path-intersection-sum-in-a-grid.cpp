const int inf = 2e9;
class Solution {
public:
    int maxScore(vector<vector<int>>& a) {
        auto f = [&] (vector<int> &a) {
            int n = a.size();
            int ret = -inf;
            for (int i=0,p=0,mn=0; i<n; i++) {
                p += a[i];
                if (i > 0) ret = max(ret, p-mn);
                if (i+1 < n-1) mn = min(mn, p);
            }
            for (int i=n-1,p=0,mn=0; i>=0; i--) {
                p += a[i];
                if (i < n-1) ret = max(ret, p-mn);
                if (i-1 > 0) mn = min(mn,p);
            }
            return ret;
        };
        auto g = [&] (vector<int> &a) {
            int n = a.size(), ret = -inf;
            vector<int> pre(n+1);
            for (int i=0; i<n; i++) {
                pre[i+1] = pre[i] + a[i];
            }
            for (int i=2,mn=0; i<=n; i++) {
                ret = max(ret, pre[i]-mn);
                mn = min(mn, pre[i-1]);
            }
            return ret;
        };
        int n = a.size(), m = a[0].size();
        int ans = -inf;
        for (int i=1; i+1<n; i++) {
            ans = max(ans, f(a[i]));
        }
        for (int j=1; j+1<m; j++) {
            vector<int> b(n);
            for (int i=0; i<n; i++) b[i] = a[i][j];
            ans = max(ans, f(b));
        }
        ans = max(ans, g(a[0]));
        ans = max(ans, g(a.back()));
        {
            vector<int> b(n);
            for (int i=0; i<n; i++) {
                b[i] = a[i][0];
            }
            ans = max(ans, g(b));
        }
        {
            vector<int> b(n);
            for (int i=0; i<n; i++) {
                b[i] = a[i][m-1];
            }
            ans = max(ans, g(b));
        }
        return ans;
    }
};
