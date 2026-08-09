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
const int inf = 2e9;
class Solution {
public:
    int maxArea(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vvi pre(n+1, vi(m+1));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                pre[i+1][j+1] = a[i][j];
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                pre[i][j] += pre[i-1][j] + pre[i][j-1];
                pre[i][j] -= pre[i-1][j-1];
            }
        }
        auto f = [&] (int i, int j, int l) {
            assert(i >= l && j >= l);
            auto ret = pre[i][j] - pre[i-l][j] - pre[i][j-l];
            ret += pre[i-l][j-l];
            return ret;
        };
        ll lo = 1, hi = min(n,m), ans = 0;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll len = mid;
            ll rmin = inf, cmin = inf;
            ll rmax = -inf, cmax = -inf;
            bool ok = false;
            for (int i=len; i<=n; i++) {
                if (ok) break;
                for (int j=len; j<=m; j++) {
                    if (ok) break; 
                    if (f(i,j,len) == len*len) {
                        if (rmin+len <= i || cmin+len <= j || cmax-len >= j) {
                            ok = true;
                            break;
                        } 
                        chmin(rmin, i);
                        chmin(cmin, j);
                        chmax(rmax, i);
                        chmax(cmax, j);
                    }
                }
            }
            if (ok) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        ans = ans * ans;
        return ans;
    }
};