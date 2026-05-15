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

class Solution {
public:
    int characterReplacement(string s, int k) {
        ll n = s.size(), sz = 26;
        ll lo = 0, hi = n, ans = -1;
        vi cnt;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            cnt.assign(sz, 0);
            bool ok = false;
            for (int i=0; i<n; i++) {
                cnt[s[i]-'A']++;
                if (i >= mid) {
                    cnt[s[i-mid]-'A']--;
                }
                int mx = *max_element(cnt.begin(), cnt.end());
                if (mid - mx <= k) ok = true;
            }
            if (ok) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};
