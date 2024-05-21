class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> ret;
        for (int mask=0; mask < (1<<n); mask++) {
            vector<int> b;
            for (int i=0; i<n; i++) {
                if ((mask>>i)&1) b.push_back(a[i]);
            }
            ret.push_back(b);
        }
        return ret;
    }
};