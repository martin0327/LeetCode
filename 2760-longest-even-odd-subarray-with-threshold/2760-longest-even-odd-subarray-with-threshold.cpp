using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& a, int k) {
        int n = a.size();
        int ans = 0;
        
        vvi b(n, vi(n)); 
        vvi c(n, vi(n)); 
        
        for (int i=0; i<n; i++) {
            b[i][i] = 1;
            c[i][i] = a[i];
            for (int j=i+1; j<n; j++) {
                b[i][j] = ((a[j]&1) != (a[j-1]&1)) & b[i][j-1];
                c[i][j] = max(c[i][j-1], a[j]);
            }
        }
        
        
        for (int i=0; i<n; i++) {
            if (a[i]&1) continue;
            for (int j=i; j<n; j++) {
                bool ok = true;
                ok &= b[i][j];  
                ok &= c[i][j] <= k;
                if (ok) ans = max(ans, j-i+1); 
            }
        }
        return ans;        
    }
};
