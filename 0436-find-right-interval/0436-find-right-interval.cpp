using vi = vector<int>;
using pii = pair<int,int>;
using ti3 = tuple<int,int,int>;
using vti3 = vector<ti3>;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& a) {
        int n = a.size();
        vti3 b(n);
        for (int i=0; i<n; i++) {
            auto &v = a[i];
            b[i] = {v[1],v[0],i};
        }
        sort(b.rbegin(), b.rend());
        vi ans(n, -1);
        set<pii> s;
        for (auto [r,l,j] : b) {
            s.insert({l,j});
            auto it = s.lower_bound({r,0});
            if (it != s.end()) {
                ans[j] = it->second;
            }
        }
        return ans;
    }
};