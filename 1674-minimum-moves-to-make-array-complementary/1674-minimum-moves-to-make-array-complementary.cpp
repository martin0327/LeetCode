const int sz = 2e5+5;
int b[sz];
class Solution {
public:
    int minMoves(vector<int>& a, int lim) {
        int n = a.size(), m = 2*lim+2;
        memset(b,0,sizeof(b)/sz*(m+1));

        b[1] = n;
        for (int i=0; i<n-1-i; i++) {
            auto x = a[i], y = a[n-1-i];
            int l = min(x,y)+1;
            int r = max(x,y)+lim;
            b[l]--;
            b[r+1]++;
            b[x+y]--;
            b[x+y+1]++;
        }

        int ans = 2e9;
        for (int i=2; i<=2*lim; i++) {
            b[i] += b[i-1];
            ans = min(ans, b[i]);
        }

        return ans;
    }
};