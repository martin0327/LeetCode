using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
const int mx_sz = 250;

int ceil_div(int a, int b) {
    return (a + b - 1) / b; // (a/b) + (a%b>0)
}

unordered_map<ll,ll> frq[mx_sz];
ll offset[mx_sz];

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& a, vector<int>& b, vector<vector<int>>& qr) {
        int n = b.size(), sz = sqrt(n); // bucket size
        int num_b = ceil_div(n, sz); // number of buckets
        for (int i=0; i<num_b; i++) {
            frq[i].clear();
        }
        memset(offset, 0, sizeof(offset));

        for (int i=0; i<n; i++) {
            int bid = i / sz, x = b[i];
            frq[bid][x]++;
        }

        vector<int> ans;
        for (auto &t : qr) {
            int tp = t[0];
            if (tp == 1) {
                ll l = t[1], r = t[2], v = t[3];
                auto l_id = l / sz;
                auto r_id = r / sz;
                if (l_id == r_id) {
                    for (int i=l; i<=r; i++) { 
                        int bid = l_id, x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+v]++;
                        b[i] += v;
                    }
                }
                else {
                    for (int bid=l_id+1; bid<r_id; bid++) {
                        offset[bid] += v;
                    }
                    for (int i=l_id*sz; i<(l_id+1)*sz; i++) {
                        if (i < l || i >= n) continue;
                        int bid = l_id, x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+v]++;
                        b[i] += v;
                    }
                    for (int i=r_id*sz; i<(r_id+1)*sz; i++) {
                        if (i > r) continue;
                        int bid = r_id, x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+v]++;
                        b[i] += v;
                    }
                }
            }
            else {
                ll tot = t[1], cnt = 0;
                for (int bid=0; bid<num_b; bid++) {
                    for (auto x : a) {
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