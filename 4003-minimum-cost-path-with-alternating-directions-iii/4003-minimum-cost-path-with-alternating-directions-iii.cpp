template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};

template<typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;
template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }

using ll = long long;
using vi = vector<ll>;
using ti4 = tuple<ll,ll,ll,ll>;
const ll inf = 2e18;
vi dr = {0,0,1,-1};
vi dc = {1,-1,0,0};
const int maxn = 1e5+1;
vi dist[2][maxn];
class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& pen) {
        for (int i=0; i<2; i++) {
            for (int j=0; j<n; j++) {
                dist[i][j] = vi(m, inf);
            }
        }
        dist[0][0][0] = 1;
        min_pq<ti4> pq;
        pq.push({1,0,0,0});
        while (pq.size()) {
            auto [d,j,r,c] = pq.top();
            pq.pop();
            if (d > dist[j][r][c]) continue;
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                int nj = j^1;
                if (nr < 0 || nr >= n) continue;
                if (nc < 0 || nc >= m) continue;
                ll cost = (nr+1) * (nc+1);
                if ((i&1) != (j&1)) cost += pen[r][c];
                ll nd = d + cost;
                if (nd < dist[nj][nr][nc]) {
                    dist[nj][nr][nc] = nd;
                    pq.push({nd,nj,nr,nc});
                }
            }
            {
                int nj = j^1, nr = r, nc = c;
                ll nd = d + pen[r][c];
                if (nd < dist[nj][nr][nc]) {
                    dist[nj][nr][nc] = nd;
                    pq.push({nd,nj,nr,nc});
                }
            }
        }
        auto ans = dist[0][n-1][m-1];
        chmin(ans, dist[1][n-1][m-1]);
        return ans;
    }
};