template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using pii = pair<int,int>;
using vp = vector<pii>;
const int sz = 201;
vp b[sz];
set<int> s[sz];

class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        for (int i=0; i<sz; i++) {
            b[i].clear();
            s[i].clear();
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                b[a[i][j]].push_back({i,j});
            }
        }
        int ans = 0;
        for (int x=sz-1; x>0; x--) {
            for (auto [r,c] : b[x]) {
                int lo = r - x, hi = r + x;
                chmax(lo, 0);
                chmin(hi, n-1);
                bool ok = true;
                for (int i=lo; i<=hi; i++) {
                    auto &st = s[i];
                    auto it = st.lower_bound(c);
                    if (it != st.end()) {
                        int d = abs(*it - c);
                        if (i == r-x || i == r + x) {
                            if (d <= x-1) ok = false;
                        }
                        else {
                            if (d <= x) ok = false;
                        }
                    }
                    if (it != st.begin()) {
                        int d  = abs(*prev(it) - c);
                        if (i == r-x || i == r+x) {
                            if (d <= x-1) ok = false;
                        }
                        else {
                            if (d <= x) ok = false;
                        }
                    }
                }
                if (ok) ans++;
            }

            for (auto [r,c] : b[x]) s[r].insert(c);
        }
        return ans;        
    }
};