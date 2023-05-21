using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vp = vector<pii>;
void chmin(ll &x, ll y) {x = min(x,y);}

vi dr = {0,0,-1,1};
vi dc = {-1,1,0,0};

const ll inf = 1e9;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& a) {
        int n = a.size();
        vvi check(n, vi(n));
        int color = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j] && !check[i][j]) {
                    queue<pii> q;
                    check[i][j] = color;
                    q.emplace(i,j);
                    while (q.size()) {
                        auto [r,c] = q.front();
                        q.pop();
                        for (int d=0; d<4; d++) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];
                            if (nr < 0 || nr >= n) continue;
                            if (nc < 0 || nc >= n) continue;
                            if (check[nr][nc]) continue;
                            if (!a[nr][nc]) continue;
                            check[nr][nc] = color;
                            q.emplace(nr,nc);
                        }
                    }
                    color++;
                }
            }
        }
        vp b;
        vvi d(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (check[i][j]==1) {
                    b.emplace_back(i,j);
                }
                else if (check[i][j]==2) {
                    d[i].push_back(j);
                }
            }
        }

        ll ans = inf;
        for (auto [r,c] : b) {
            for (int i=0; i<n; i++) {
                if (d[i].size()) {
                    auto it = lower_bound(d[i].begin(), d[i].end(), c);
                    if (it != d[i].end()) chmin(ans, abs(r-i)+abs(*it-c)-1);
                    if (it != d[i].begin()) chmin(ans, abs(r-i)+abs(*prev(it)-c)-1);
                }
            }
        }
        return ans;
    }
};

