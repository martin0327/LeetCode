using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;

vi dx = {0,1,0,-1};
vi dy = {1,0,-1,0};

class Solution {
public:
    int robotSim(vector<int>& comm, vector<vector<int>>& obs) {
        int d = 0, x = 0, y = 0, ans = 0;
        set<pii> s;
        for (auto v : obs) {
            s.insert({v[0],v[1]});
        }
        for (auto k : comm) {
            if (k < 0) d = (d-2*k-1) % 4;
            else {
                while (k--) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (s.count({nx,ny})) break;
                    x = nx, y = ny;
                }
                ans = max(ans, x*x+y*y);
            }
        }
        return ans;
    }
};