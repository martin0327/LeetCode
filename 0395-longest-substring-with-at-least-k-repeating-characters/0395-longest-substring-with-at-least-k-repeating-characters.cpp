template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
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
            for (auto j : p) {
                bool ok = true;
                for (auto [l,r] : b) {
                    if (r == n+1) ok &= j <= l;
                    else ok &= (j <= l || j >= r);
                }
                if (ok) chmax(ans, j-i);
            }
        }
        return ans;
    }
};
