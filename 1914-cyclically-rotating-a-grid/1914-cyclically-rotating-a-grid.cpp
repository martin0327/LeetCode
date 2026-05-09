using vi = vector<int>;
using pii = pair<int,int>;
using vp = vector<pii>;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        vp rc;
        vi t;
        for (int i=0; i<min(n,m)/2; i++) {
            vi rs = {i,n-1-i};
            vi cs = {i,m-1-i};
            vp b;
            for (auto r : rs) {
                for (auto c : cs) {
                    b.push_back({r,c});
                }
            }
            swap(b[2],b[3]);
            rc.clear();
            for (int j=0; j<4; j++) {
                auto [r,c] = b[j];
                auto [tr,tc] = b[(j+1)%4];
                while (r != tr || c != tc) {
                    rc.push_back({r,c});
                    int dr = tr - r;
                    int dc = tc - c;
                    if (dr != 0) r += dr / abs(dr);
                    if (dc != 0) c += dc / abs(dc);
                }
            }

            int sz = rc.size();
            t.resize(sz);
            for (int j=0; j<sz; j++) {
                auto [r,c] = rc[j];
                t[j] = a[r][c];
            }
            for (int j=0; j<sz; j++) {
                auto [r,c] = rc[j];
                a[r][c] = t[(j+k)%sz];
            }
        }
        return a;
    }
};