class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        int n = a.size(), m = l.size();
        vector<bool> ans(m);
        for (int i=0; i<m; i++) {
            vector<int> b;
            for (int j=l[i]; j<=r[i]; j++) {
                b.push_back(a[j]);
            }
            sort(b.begin(), b.end());
            int k = b.size();
            bool ok = true;
            for (int j=1; j<k; j++) {
                ok &= ((b[j]-b[j-1]) == (b[1]-b[0]));
            }
            ans[i] = ok;
        }
        return ans;
    }
};