class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int n = a.size();
        int l,r,ans,x,y;
        l = r = k, ans = x = y = a[k];
        
        auto f = [&] () {
            ans = max(ans, (r-l+1) * min(x,y));
        };
        
        while (l > 0 && r < n-1) {
            int nx = min(x, a[l-1]);
            int ny = min(y, a[r+1]);
            if (nx >= ny) {
                l--;
                x = nx;
            }
            else {
                r++;
                y = ny;
            }
            f();
        }
        while (l > 0) {
            x = min(x, a[--l]);
            f();
        }
        while (r < n-1) {
            y = min(y, a[++r]);
            f();
        }
        
        return ans; 
    }
};