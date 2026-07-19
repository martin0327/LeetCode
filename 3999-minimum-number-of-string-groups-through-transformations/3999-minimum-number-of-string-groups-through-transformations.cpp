struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
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
    asort(a);
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

////////////////////////////////////
// using i128 = __int128_t;
struct rabin_karp {
    size_t n;
    ll B, P;                          // base and modulus for this instance
    inline static const ll defaultP = (1ll<<30)-1;

    static std::mt19937_64 rng;         // shared RNG for all instances

    std::vector<ll> pw;               // pw[i] = B^i mod P
    std::vector<ll> h;                // prefix hashes

    // --- helper: get a random base in [1000, sqrt(P)] ---
    static ll random_base(ll P) {
        std::uniform_int_distribution<long long> dist(
            1000,
            (long long)std::sqrt((long double)P)
        );
        return dist(rng);
    }

    // --- helper for string → vector<int> ---
    static std::vector<int> to_vec(const std::string &s) {
        std::vector<int> a(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            a[i] = (unsigned char)s[i];
        }
        return a;
    }

    // --- core constructor: explicit base + modulus ---
    rabin_karp(const std::vector<int> &a, ll B, ll P = defaultP)
        : n(a.size()), B(B), P(P), pw(n + 1, 1), h(n + 1, 0) {

        // pw[i] = B^i mod P
        for (int i = 1; i <= (int)n; i++) {
            pw[i] = (pw[i - 1] * B) % P;
        }

        // backward-style prefix hash:
        // h[i+1] = h[i]*B + a[i]   (mod P)
        for (int i = 0; i < (int)n; i++) {
            h[i+1] = ((h[i] * B )%P + a[i]) % P;
        }
    }

        rabin_karp(const std::vector<int> &a, ll P = defaultP)
        : rabin_karp(a, random_base(P), P) {}

    // --- string constructor: explicit base B, explicit P ---
    rabin_karp(const std::string &s, ll B, ll P)
        : rabin_karp(to_vec(s), B, P) {}

    // --- convenience constructor: random base, given modulus (or defaultP) ---
    rabin_karp(const std::string &s, ll P = defaultP)
        : rabin_karp(to_vec(s), random_base(P), P) {}



    // hash of substring [l, r] (0-indexed, inclusive)
    ll query(int l, int r) const {
        assert(0 <= l && l <= r && (size_t)r < n);
        int len = r - l + 1;

        // x = h[r+1] - h[l] * B^len
        ll x = h[r + 1] - ( h[l] * pw[len] ) % P;
        x %= P;
        if (x < 0) x += P;
        return x;
    }

    // optional helpers if you want to inspect parameters
    ll base() const { return B; }
    ll mod()  const { return P; }
};

// static RNG definition
std::mt19937_64 rabin_karp::rng(
    std::chrono::steady_clock::now().time_since_epoch().count()
);



////////////////////////////////////

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5+1;
vector<int> a[maxn];

class Solution {
public:
    int minimumGroups(vector<string>& b) {
        int n = b.size();
        for (int i=0; i<n; i++) a[i].clear();
        for (int i=0; i<n; i++) {
            int m = b[i].size();
            a[i] = vector<int>(m);
            for (int j=0; j<m; j++) {
                a[i][j] = b[i][j] - 'a' + 1;
            }
        }
        ll P = (1ll << 30) - 1;
        ll B = 1729;
        vector<rabin_karp> rk1(n, rabin_karp("af")), rk2(n, rabin_karp("af"));
        auto concat = [&] (vector<int> a, vector<int> b) {
            for (auto x : b) a.push_back(x);
            return a;
        };
        vector<ll> cx;
        vi m1s(n), m2s(n);
        for (int i=0; i<n; i++) {
            int m = a[i].size();
            vector<int> a1,a2;
            for (int j=0; j<m; j++) {
                if (j&1) a1.push_back(a[i][j]);
                else a2.push_back(a[i][j]);
            }
            a1 = concat(a1,a1);
            a2 = concat(a2,a2);
            rk1[i] = rabin_karp(a1,B,P);
            rk2[i] = rabin_karp(a2,B,P);
            int m1 = a1.size();
            int m2 = a2.size();
            m1s[i] = m1;
            m2s[i] = m2;
            if (m1 > 0) {
                for (int j=0; j+(m1/2)-1<m1; j++) {
                    auto val = rk1[i].query(j,j+(m1/2)-1);
                    cx.push_back(val);
                }
            }
            if (m2 > 0) {
                for (int j=0; j+(m2/2)-1<m2; j++) {
                    auto val = rk2[i].query(j,j+(m2/2)-1);
                    cx.push_back(val);
                }
            }
        }
        cx = get_unique(cx);
        int sz = cx.size();
        auto gi = [&] (ll x) {
            auto it = lower_bound(cx.begin(), cx.end(), x);
            return it - cx.begin();
        };
        dsu uf(sz);
        for (int i=0; i<n; i++) {
            int m1 = m1s[i];
            int m2 = m2s[i];
            ll val1, val2;
            if (m1 > 0) {
                for (int j=0; j+(m1/2)-1<m1; j++) {
                    auto val = rk1[i].query(j,j+(m1/2)-1);
                    if (j == 0) {
                        val1 = gi(val);
                        if (uf.size(val1) > 1) break;
                    }
                    else {
                        uf.merge(val1,gi(val));
                    }
                }
            }
            if (m2 > 0) {
                for (int j=0; j+(m2/2)-1<m2; j++) {
                    auto val = rk2[i].query(j,j+(m2/2)-1);
                    if (j == 0) {
                        val2 = gi(val);
                        if (uf.size(val2) > 1) break;
                    }
                    else {
                        uf.merge(val2,gi(val));
                    }
                }
            }
        }
        vp sp;
        for (int i=0; i<n; i++) {
            int m1 = m1s[i], m2 = m2s[i];
            auto val1 = (m1 > 0) ? rk1[i].query(0,(m1/2)-1) : -1;
            auto val2 = (m2 > 0) ? rk2[i].query(0,(m2/2)-1) : -1;
            pii tg = {(val1==-1)?-1:uf.leader(gi(val1)), (val2==-1)?-1:uf.leader(gi(val2))};
            sp.push_back(tg);
        }
        
        int ans = get_unique(sp).size();
        return ans;
    }
};