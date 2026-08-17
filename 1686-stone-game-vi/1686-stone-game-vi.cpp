using pii = pair<int,int>;
class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<pii> c(n);
        for (int i=0; i<n; i++) {
            c[i] = {a[i]+b[i],i};
        }
        sort(c.rbegin(), c.rend());
        int x = 0, y = 0;
        for (int i=0; i<n; i++) {
            auto [z,j] = c[i];
            if (i&1) y += b[j];
            else x += a[j];
        }
        if (x > y) return 1;
        if (x < y) return -1;
        return 0;
    }
};