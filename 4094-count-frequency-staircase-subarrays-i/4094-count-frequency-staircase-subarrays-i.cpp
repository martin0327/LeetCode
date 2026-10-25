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
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;

const int mx_sz = 1e5+1;
const int mx_n = 1e5+1;
const int mx_m = 500;
vi idx[mx_sz];
set<pii> sp;
vi b[mx_n];
vi c[mx_n];
class Solution {
public:
    int countStaircase(vector<int>& a) {
        auto sz = *max_element(a.begin(), a.end()) + 1;
        for (int i=0; i<sz; i++) {
            idx[i].clear();
        }
        int n = a.size();
        for (int i=0; i<n; i++) {
            idx[a[i]].push_back(i);
        }
        int m = sqrt(2*n+10);
        vi pre = {1};
        for (int i=2; pre.size()<=m; i++) {
            pre.push_back(pre.back()+i);
        }
        vi inv(n+1,-1);
        for (int i=0; i<n; i++) {
            auto x = i+1;
            auto it = lower_bound(pre.begin(), pre.end(), x);
            inv[x] = it - pre.begin();
        }
        // debug(inv);

        vi vis(sz);
        sp.clear();
        for (int i=0; i<n; i++) {
            auto x = a[i];
            if (vis[x]) continue;
            sp.insert({i,x});
            vis[x] = 1;
        }
        ll ans = 0;
        // vvi b(n, vi(m,-1));
        for (int i=0; i<n; i++) {
            b[i] = vi(m,-1);
        }
        for (int i=0; i<n; i++) {
            auto it = sp.begin();
            for (int j=0; j<m; j++) {
                if (it == sp.end()) break;
                auto [w,x] = *it;
                b[i][j] = x;
                it++;
            }
            it = sp.begin();
            auto [w,x] = *it;
            sp.erase(it);
            auto &v = idx[x];
            auto it2 = upper_bound(v.begin(), v.end(), w);
            if (it2 != v.end()) {
                auto w = *it2;
                sp.insert({w,x});
            }
        }
        // b[i][j] : for a subarray that starts at i, the (j+1)-th distinct elm is b[i][j]
        // vvi c(n, vi(m+1,n));
        for (int i=0; i<n; i++) {
            c[i] = vi(m+1,n);
        }
        for (int i=0; i<n; i++) {
            auto x = a[i];
            auto &v = idx[x];
            auto it = lower_bound(v.begin(), v.end(),i);
            for (int j=0; j<=m; j++) {
                if (it == v.end()) break;
                c[i][j] = *it;
                it++;
            }
        }
        // c[i][j] : for x = a[i], starting from i, the (j+1)-th appearance of x hapens at index c[i][j]

        vi cnt(m);
        for (int i=0; i<n; i++) {
            int lim = n;
            cnt.assign(m,0);
            for (int j=0; j<m; j++) {
                auto x = b[i][j];
                if (x == -1) break;
                auto &v = idx[x];
                auto it = lower_bound(v.begin(), v.end(), i);
                assert(it != v.end());
                auto i2 = *it;
                chmin(lim, c[i2][j+1]);
                auto r = c[i2][j];
                int d = r - i + 1;
                // debug(i,j,x,d,inv[d]);
                if (0 <= d && d <= n && 0 <= inv[d] && inv[d] < m) {
                    cnt[inv[d]]++;
                }
            }
            for (int j=1; j<m; j++) {
                cnt[j] += cnt[j-1];
            }
            // debug(cnt);
            int cum = 0;
            for (int j=0; j<m; j++) {
                cum += j+1;
                if (i + cum - 1 >= lim) break;
                if (cnt[j] == j+1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};