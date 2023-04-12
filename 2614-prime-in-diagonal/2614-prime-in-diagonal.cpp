class Solution {
public:
    int diagonalPrime(vector<vector<int>>& a) {
        int ans = 0, n = a.size();
        for (int i=0; i<n; i++) {
            for (int j : {i, n-1-i}) {
                int x = a[i][j];
                bool prime = x != 1;
                for (int j=2; j*j<=x; j++) {
                    if (x % j == 0) prime = false;
                }
                if (prime) ans = max(ans, x);
            }
        }
        return ans;
    }
};