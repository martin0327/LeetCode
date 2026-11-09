
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
using vvs = vector<vs>;

using S = ll;
S op(S x, S y) { return x + y; }
S e() { return 0ll; }
const ll inf = 2e18;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& aa, vector<int>& bb) {
        vi a(aa.begin(), aa.end());
        vi b(bb.begin(), bb.end());
        vi cnt(k);
        set<ll> s;
        for (int i=0; i<k; i++) s.insert(i);
        min_pq<pii> pq;
        int n = a.size();
        for (int i=0; i<n; i++) {
            auto x = a[i];
            while (pq.size()) {
                auto [y,j] = pq.top();
                if (y <= x) {
                    pq.pop();
                    s.insert(j);
                }
                else break;
            }
            if (s.empty()) continue;
            auto it = s.lower_bound(i%k);
            if (it == s.end()) it = s.begin();
            auto j = *it;
            cnt[j]++;
            s.erase(it);
            pq.push({x+b[i],j});
        }
        auto mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i=0; i<k; i++) {
            if (cnt[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};