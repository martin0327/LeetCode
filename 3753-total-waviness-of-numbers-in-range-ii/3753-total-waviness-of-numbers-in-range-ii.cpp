
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

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;

const int sz = 15;
class Solution {
public:
    long long totalWaviness(long long A, long long B) {
        function<ll(ll)> f = [&] (ll y) {
            auto s = to_string(y);
            ll ret = 0, n = s.size();
            vi a(n);
            for (int i=0; i<n; i++) {
                a[i] = s[i] - '0';
            }
            Vec<6,ll> dp(n+1,2,2,3,10,sz);
            dp[0][0][0][0][0][0] = 1;
            for (int i=0; i<n; i++) {
                for (int tb=0; tb<2; tb++) {
                    for (int lz=0; lz<2; lz++) {
                        for (int j=0; j<3; j++) {
                            for (int l=0; l<10; l++) {
                                for (int x=0; x<sz; x++) {
                                    if (dp[i][tb][lz][j][l][x] == 0) continue;
                                    for (int d=0; d<=(tb?9:a[i]); d++) {
                                        int ntb = tb | (d < a[i]);
                                        int nlz = lz | (d != 0);
                                        int nj = 0;
                                        if (d < l) nj = 1;
                                        if (d > l) nj = 2;
                                        if (lz == 0) nj = 0;
                                        int nl = d;
                                        int nx = x + (j+nj==3);
                                        dp[i+1][ntb][nlz][nj][nl][nx] += dp[i][tb][lz][j][l][x];
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (int tb=0; tb<2; tb++) {
                for (int lz=0; lz<2; lz++) {
                    for (int j=0; j<3; j++) {
                        for (int l=0; l<10; l++) {
                            for (int x=0; x<sz; x++) {
                                ret += dp[n][tb][lz][j][l][x] * x;
                            }
                        }
                    }
                }
            }
            return ret;
        };
        auto ans = f(B) - f(A-1);
        // debug(B,f(B));
        // debug(A-1,f(A-1));
        return ans;
    }
};