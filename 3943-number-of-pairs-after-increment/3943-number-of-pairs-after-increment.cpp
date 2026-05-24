
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

const ll mx_sz = 250;
unordered_map<ll,ll> frq[mx_sz];
ll offset[mx_sz];

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b; // a / b + (a % b > 0)
}
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& a, vector<int>& b, vector<vector<int>>& qr) {
        int n = a.size(), m = b.size();
        int q = qr.size(), sz = sqrt(m); // bucket size
        int num_b = ceil_div(m, sz); // number of buckets
        for (int i=0; i<num_b; i++) {
            frq[i].clear();
        }
        memset(offset, 0, sizeof(offset));

        for (int i=0; i<m; i++) {
            ll bid = i / sz, x = b[i];
            frq[bid][x]++;
        }

        vector<int> ans;
        for (auto &t : qr) {
            ll tp = t[0];
            if (tp == 1) {
                ll l = t[1], r = t[2], val = t[3];
                auto l_id = l / sz;
                auto r_id = r / sz;
                if (l_id == r_id) {
                    for (int i=l; i<=r; i++) { 
                        ll bid = l_id, x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+val]++;
                        b[i] += val;
                    }
                }
                else {
                    for (int bid=l_id+1; bid<r_id; bid++) {
                        offset[bid] += val;
                    }
                    for (int i=l_id*sz; i<(l_id+1)*sz; i++) {
                        if (i < l || i >= m) continue;
                        ll bid = l_id, x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+val]++;
                        b[i] += val;
                    }
                    for (int i=r_id*sz; i<(r_id+1)*sz; i++) {
                        if (i > r || i < 0) continue;
                        ll bid = r_id, x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+val]++;
                        b[i] += val;
                    }
                }
            }
            else {
                ll tot = t[1], cnt = 0;
                for (int bid=0; bid<num_b; bid++) {
                    for (auto x : a) { // at most 5 elements
                        // x + y + offset = tot
                        // y = tot - x - offset
                        auto tg = tot - x - offset[bid];
                        if (frq[bid].count(tg)) {
                            cnt += frq[bid][tg];
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }

        return ans;
    }
};