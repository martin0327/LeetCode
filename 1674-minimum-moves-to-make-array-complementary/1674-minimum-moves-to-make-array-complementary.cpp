const int sz = 2e5+5;
int b[sz];
class Solution {
public:
    int minMoves(vector<int>& a, int lim) {
        int n = a.size(), m = 2*lim+2;
        memset(b,0,sizeof(b));
        for (int i=0; i<n-1-i; i++) {
            auto x = a[i], y = a[n-1-i];
            int l = min(x,y)+1;
            int r = max(x,y)+lim;
            b[l]--;
            b[r+1]++;
            b[1] += 2;
        }
        for (int i=2; i<m; i++) {
            b[i] += b[i-1];
        }
        for (int i=0; i<n-1-i; i++) {
            auto x = a[i], y = a[n-1-i];
            b[x+y]--;
        }

        int ans = 2e9;
        for (int i=2; i<=2*lim; i++) 
            ans = min(ans, b[i]);

        return ans;
    }
};