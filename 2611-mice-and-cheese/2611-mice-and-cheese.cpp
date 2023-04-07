class Solution {
public:
    int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<pair<int,int>> c(n);
        for (int i=0; i<n; i++) {
            c[i] = {a[i] - b[i],i};
        }
        sort(c.rbegin(), c.rend());
        vector<int> d(n);
        for (int i=0; i<k; i++) {
            d[c[i].second] = 1;
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (d[i]) ans += a[i];
            else ans += b[i];
        }
        return ans;
    }
};