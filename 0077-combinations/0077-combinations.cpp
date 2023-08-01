class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        for (int m=0; m<(1<<n); m++) {
            if (__builtin_popcount(m) != k) continue;
            vector<int> a;
            for (int i=0; i<n; i++) {
                if (m>>i&1) a.push_back(i+1);
            }
            ret.push_back(a);
        }
        return ret;        
    }
};