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

const ll inf = 2e18;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vi a(nums.begin(), nums.end());
        int n = a.size();
        a.insert(a.begin(), 0ll);
        vi b(n+1), c(n+1);
        for (int i=1; i<=n; i++) {
            b[i] = a[i] * k;
            c[i] = a[i] / k;
        }
        vi pre(n+1), suf(n+2);
        vi p1(n+1,-inf), s1(n+2,0);
        p1[0] = 0, s1[n+1] = 0;
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i];
        }
        for (int i=1, mn=0; i<=n; i++) {
            chmax(p1[i], pre[i]-mn);
            chmin(mn, pre[i]);
        }
        for (int i=n; i>=1; i--) {
            suf[i] = suf[i+1] + a[i];
        }
        for (int i=n, mn=0; i>=1; i--) {
            chmax(s1[i], suf[i]-mn);
            chmin(mn, suf[i]);
        }
        // debug(suf);
        // debug(s1);

        auto f = [&] (vi b) {
            vi p2(n+1);
            for (int i=1; i<=n; i++) {
                p2[i] = p2[i-1] + b[i];
            }
            // debug(p2);
            // debug(pre);
            ll ret = pre[n], t = 0;
            for (int i=1, mn = 0; i<=n; i++) {
                chmax(ret, p2[i] + s1[i+1] + t);
                chmin(mn, pre[i]);
                chmax(t, pre[i] - p2[i] - mn);
            }
            return ret;
        };
        auto ans = max(f(b), f(c));
        return ans;
    }
};