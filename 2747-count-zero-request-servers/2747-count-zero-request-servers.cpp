
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
using vvs = vector<vs>;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int len, vector<int>& qr) {
        vi cx;
        map<int,vi> t2i;
        for (auto &v : logs) {
            auto i = v[0], t = v[1];
            cx.push_back(t);
            cx.push_back(t+len+1);
            t2i[t].push_back(i);
        }
        int q = qr.size();
        vector<int> ans(q);
        map<int,vi> off;
        for (int i=0; i<q; i++) {
            auto &t = qr[i];
            off[t].push_back(i);
            cx.push_back(t);
        }
        cx = get_unique(cx);
        int sz = cx.size();
        auto g = [&] (int x) {
            auto it = lower_bound(cx.begin(), cx.end(), x);
            return it - cx.begin();
        };
        vi cnt(n+1);
        int cur = 0;
        for (int i=0; i<sz; i++) {
            auto t = cx[i];
            for (auto id : t2i[t]) {
                cnt[id]++;
                if (cnt[id] == 1) cur++;
            }
            auto p = t-len-1;
            if (t2i.count(p)) {
                for (auto id : t2i[p]) {
                    cnt[id]--;
                    if (cnt[id] == 0) cur--;
                }
            }
            for (auto idx : off[t]) {
                ans[idx] = n - cur;
            }
        }
        return ans;
    }
};