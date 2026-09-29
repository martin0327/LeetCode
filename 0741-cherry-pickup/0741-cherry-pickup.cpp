template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}
template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using ti4 = tuple<int,int,int,int>;
const int sz = 51;
int dp[sz][sz][sz][sz];
bool vis[sz][sz][sz][sz];
vi dr = {0,1}, dc = {1,0};
class Solution {
public:
    int cherryPickup(vector<vector<int>>& a) {
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        int n = a.size();
        vi ds = {0,1};
        auto check = [&] (int r, int c) {
            if (r >= n || c >= n) return false;
            return a[r][c] != -1;
        };
        auto conn = [&] () {
            queue<pii> q;
            vvi vis(n, vi(n));
            vis[0][0] = 1;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (!vis[i][j]) continue;
                    for (auto d : ds) {
                        int r = i + dr[d];
                        int c = j + dc[d];
                        if (!check(r,c)) continue;
                        vis[r][c] = 1;
                    }
                }
            }
            return vis.back().back();
        };
        if (!conn()) return 0;
        
        dp[0][0][0][0] = a[0][0];
        queue<ti4> q;
        q.emplace(0,0,0,0);
        while (q.size()) {
            auto [r1,c1,r2,c2] = q.front();
            q.pop();
            for (auto d1 : ds) {
                int nr1 = r1 + dr[d1];
                int nc1 = c1 + dc[d1];
                if (!check(nr1,nc1)) continue;
                for (auto d2 : ds) {
                    int nr2 = r2 + dr[d2];
                    int nc2 = c2 + dc[d2];
                    if (!check(nr2,nc2)) continue;
                    auto &nv = vis[nr1][nc1][nr2][nc2];
                    auto &nd = dp[nr1][nc1][nr2][nc2];
                    auto val = a[nr1][nc1] + a[nr2][nc2];
                    if (val > 0 && nr1 == nr2 && nc1 == nc2) val--;
                    if (!nv) {
                        nv = 1;
                        q.emplace(nr1,nc1,nr2,nc2);
                        chmax(nd, dp[r1][c1][r2][c2] + val);
                    }
                    else {
                        chmax(nd, dp[r1][c1][r2][c2] + val);
                    }
                }
            }
        }
        auto ans = dp[n-1][n-1][n-1][n-1];
        return ans;
    }
};