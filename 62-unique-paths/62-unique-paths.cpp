class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n==1 || m==1) return 1;
        n--; m--;
        if (m<n) swap(n,m);
        long long ans = 1;
        int i = m+1, j = 1;
        while (i<=n+m) {
            ans *= i++;
            ans /= j++;
        }
        return ans;
    }
};