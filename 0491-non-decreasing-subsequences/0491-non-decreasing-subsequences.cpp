using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& a) {
        int n = a.size();
        vvi ret;
        set<vi> s;
        for (int msk=0; msk<(1<<n); msk++) {
            vi b;
            for (int i=0; i<n; i++) {
                if (msk>>i&1) b.push_back(a[i]);
            }
            if (b.size() < 2) continue;
            vi c = b;
            sort(c.begin(), c.end());
            if (b==c) s.insert(b);
        }
        for (auto &v : s) ret.push_back(v);
        return ret;        
    }
};