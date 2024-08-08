using vi = vector<int>;
using vvi = vector<vi>;
vi dr = {0,1,0,-1};
vi dc = {1,0,-1,0};

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int rs, int cs) {
        int r = rs, c = cs, d = 0, p = 1;
        vvi ans;
        auto f = [&] () {
            return 0<=r && r<n && 0<=c && c<m;
        };
        while (ans.size() < n*m) {
            p++;
            int t = p/2;
            while (t--) {
                if (f()) ans.push_back({r,c});
                if (ans.size() == n*m) break;
                r += dr[d];
                c += dc[d];
            }
            d = (d+1) % 4;
        }
        return ans;
    }
};