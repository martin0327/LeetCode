using pii = pair<int,int>;
using vp = vector<pii>;
using vvp = vector<vp>;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& a, int lim) {
        int n = a.size();
        vp b(n);
        for (int i=0; i<n; i++) b[i] = {a[i],i};
        sort(b.begin(), b.end());
        vvp c;
        for (auto [x,i] : b) {
            if (c.empty() || x - c.back().back().first > lim) c.push_back({make_pair(x,i)});
            else c.back().push_back({x,i});
        }
        vector<int> ans(n);
        for (auto v : c) {
            vector<int> d,idx;
            for (auto [x,i] : v) {
                d.push_back(x);
                idx.push_back(i);
            }
            sort(idx.begin(), idx.end());
            int sz = d.size();
            for (int j=0; j<sz; j++) {
                ans[idx[j]] = d[j];
            }
        }
        return ans;
    }
};