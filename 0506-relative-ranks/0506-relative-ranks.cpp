class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        iota(b.begin(), b.end(), 0);
        sort(b.begin(), b.end(), [&] (int i, int j) { return a[i] > a[j]; });
        vector<string> ans(n);
        for (int i=0; i<n; i++) {
            if (i == 0) ans[b[i]] = "Gold Medal";
            else if (i == 1) ans[b[i]] = "Silver Medal";
            else if (i == 2) ans[b[i]] = "Bronze Medal";
            else ans[b[i]] = to_string(i+1);
        }
        return ans;
    }
};