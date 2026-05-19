
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

const int sz = 1e5+1;
class Solution {
public:
    long long countSubarrays(vector<int>& aa, int k, int m) {
        vi a(aa.begin(), aa.end());
        ll n = a.size(), ans = 0;
        vi c1(sz), c2(sz);
        set<pii> s1, s2;
        auto f = [&] (int x) {
            pii tg1 = {c1[x],x};
            pii tg2 = {c2[x],x};
            if (s1.count(tg1)) s1.erase(tg1);
            if (s2.count(tg2)) s2.erase(tg2);
            s1.insert({++c1[x],x});
            s2.insert({++c2[x],x});
        };
        
        auto g1 = [&] (int x) {
            pii tg = {c1[x],x};
            if (s1.count(tg)) s1.erase(tg);
            if (--c1[x] > 0) {
                s1.insert({c1[x],x});
            }
        };

        auto g2 = [&] (int x) {
            pii tg = {c2[x],x};
            if (s2.count(tg)) s2.erase(tg);
            if (--c2[x] > 0) {
                s2.insert({c2[x],x});
            }
        };

        for (int i=0,l=0,r=0; i<n; i++) {
            f(a[i]);
            while (s2.size() > k) {
                g2(a[r++]);
            }
            while (s2.size() == k && (s2.begin()->first) >= m) {
                if (c2[a[r]] > m) g2(a[r++]);
                else break;
            }
            while (s1.size() > k) {
                g1(a[l++]);
            }
            if (s2.size() == k && (s2.begin()->first) >= m) {
                ans += r-l+1;
            }
        }
        return ans;
    }
};