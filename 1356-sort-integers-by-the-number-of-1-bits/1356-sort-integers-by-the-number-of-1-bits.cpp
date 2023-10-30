class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        int n = a.size();
        vector<pair<int,int>> b(n);
        for (int i=0; i<n; i++) {
            b[i] = {__builtin_popcount(a[i]),a[i]};
        }
        sort(b.begin(), b.end());
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            ans[i] = b[i].second;
        }
        return ans;
    }
};