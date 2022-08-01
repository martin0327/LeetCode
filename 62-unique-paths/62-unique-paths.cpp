class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n==1 || m==1) return 1;
        n--; m--;
        if (m<n) swap(n,m);
        long long ans = 1;
        int i = m+1;
        int j = 1;
        while (i<=n+m || j<=n) {
            if (j <= n && ans % j == 0) ans /= j++;
            else if (i<=n+m) ans *= i++;
        }
        return ans;
    }
};