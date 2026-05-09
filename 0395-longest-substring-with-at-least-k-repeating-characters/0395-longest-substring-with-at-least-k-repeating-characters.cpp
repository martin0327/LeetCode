
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
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), sz = 26;
        vvi pre(sz,vi(n+1));
        for (int i=0; i<n; i++) {
            int x = s[i] - 'a';
            for (int j=0; j<sz; j++) {
                pre[j][i+1] = pre[j][i] + (x == j);
            }
        }
        // debug(pre);
        int ans = 0;
        for (int i=0; i<n; i++) {
            vp b;
            vi p = {n};
            for (int j=0; j<sz; j++) {
                auto &v = pre[j];
                if (v[n] == v[i]) continue;
                // pre[j][r] - pre[j][i] > 0 smallest such idx
                // pre[j][r] - pre[j][i] >= k smallest such idx
                auto it1 = upper_bound(v.begin(), v.end(), v[i]);
                auto it2 = lower_bound(v.begin(), v.end(), v[i]+k);
                auto l = it1 - v.begin() - 1, r = it2 - v.begin();
                b.push_back({l,r});
                p.push_back(l);
                p.push_back(r);
            }
            p = get_unique(p);
            // debug(b);
            // debug(p);
            for (auto j : p) {
                bool ok = true;
                for (auto [l,r] : b) {
                    if (r == n+1) {
                        ok &= j <= l;
                    }
                    else {
                        if (l < j && j < r) ok = false;
                    }
                    // if (i == 0) {
                    //     debug(j,l,r);
                    // }
                    // if (l < j && j < r) ok = false;
                }
                if (ok) chmax(ans, j-i);
            }
        }
        return ans;
    }
};
