using ll = long long;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n==1 || m==1) return 1;
        n--; m--;
        if (m<n) swap(n,m);
        ll ans = 1;
        int i = m+1, j = 1;
        while (i<=n+m || j<=n) {
            if (j <= n && ans % j == 0) ans /= j++;
            else ans *= i++;
        }
        return ans;
    }
};