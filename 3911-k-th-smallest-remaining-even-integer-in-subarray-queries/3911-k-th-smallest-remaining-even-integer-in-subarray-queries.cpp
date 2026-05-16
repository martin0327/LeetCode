
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
    vector<int> kthRemainingInteger(vector<int>& aa, vector<vector<int>>& qr) {
        vi a(aa.begin(), aa.end());
        int n = a.size();
        vi b(n);
        for (int i=0; i<n; i++) {
            if (a[i] % 2 == 0) b[i] = 1;
        }
        for (int i=1; i<n; i++) b[i] += b[i-1];

        vector<int> res;
        for (auto &v : qr) {
            ll l = v[0], r = v[1], k = v[2];
            ll lo = 1, hi = 2e9, ans = -1; 
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                // how many even numbers are there in
                // a[l...r] s.t. a[i] <= 2*mid
                // even numbers in a[0...r] s.t.  a[i] <= 2*mid
                // even numbers in a[0...l-1] s.t.  a[i] <= 2*mid
                auto it1 = upper_bound(a.begin(), a.end(), 2*mid);
                ll idx1 = it1 - a.begin() - 1;
                chmin(idx1, r);
                auto it2 = upper_bound(a.begin(), a.end(), 2*mid);
                ll idx2 = it2 - a.begin() - 1;
                chmin(idx2, l-1);
                ll cnt = 0;
                if (idx1 >= 0) cnt += b[idx1];
                if (idx2 >= 0) cnt -= b[idx2];
                if (mid - cnt >= k) {
                    ans = mid;
                    hi = mid -1;
                }
                else lo = mid + 1;
            }
            res.push_back(2*ans);
        }
        return res;
    }
};