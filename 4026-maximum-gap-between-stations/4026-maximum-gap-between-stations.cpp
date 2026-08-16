template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}
using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    int maximumGap(string s, string t) {
        int n = s.size(), m = t.size(), sz = 26;
        vvi idx(sz);
        for (int i=0; i<m; i++) {
            idx[t[i]-'a'].push_back(i);
        }
        vi L,R;
        for (int i=0, cur = -1; i<n; i++) {
            int x = s[i] - 'a';
            auto &v = idx[x];
            auto it = upper_bound(v.begin(), v.end(), cur);
            assert(it != v.end());
            L.push_back(cur = *it);
        }
        for (int i=n-1,cur=m; i>=0; i--) {
            int x = s[i] - 'a';
            auto &v = idx[x];
            auto it = lower_bound(v.begin(), v.end(), cur);
            assert(it != v.begin());
            R.push_back(cur = *prev(it));
        }
        reverse(R);
        int ans = 0;
        for (int i=1; i<n; i++) {
            chmax(ans, R[i]-L[i-1]);
        }
        return ans;
    }
};