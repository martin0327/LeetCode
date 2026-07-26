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
class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& pen) {
        Vec<3,ll> dist(n,m,2,inf);
        dist[0][0][0] = 1;
        min_pq<ti4> pq;
        pq.push({1,0,0,0});
        while (pq.size()) {
            auto [d,r,c,j] = pq.top();
            pq.pop();
            if (d > dist[r][c][j]) continue;
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                int nj = j^1;
                if (nr < 0 || nr >= n) continue;
                if (nc < 0 || nc >= m) continue;
                ll cost = (nr+1) * (nc+1);
                if ((i%2) != (j&1)) cost += pen[r][c];
                ll nd = d + cost;
                if (nd < dist[nr][nc][nj]) {
                    dist[nr][nc][nj] = nd;
                    pq.push({nd,nr,nc,nj});
                }
            }
            {
                int nj = j^1;
                ll cost = pen[r][c];
                ll nd = d + cost;
                if (nd < dist[r][c][nj]) {
                    dist[r][c][nj] = nd;
                    pq.push({nd,r,c,nj});
                }
            }
        }
        auto ans = dist[n-1][m-1][0];
        chmin(ans, dist[n-1][m-1][1]);
        return ans;
    }
};