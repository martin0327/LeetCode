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
        int n = a.size(), m = b.size();
        int q = qr.size(), sz = sqrt(m); // bucket size
        int num_b = ceil_div(m, sz); // number of buckets
        for (int i=0; i<num_b; i++) {
            frq[i].clear();
        }
        memset(offset, 0, sizeof(offset));

        for (int i=0; i<m; i++) {
            int bid = i / sz, x = b[i];
            frq[bid][x]++;
        }

        vector<int> ans;
        for (auto &t : qr) {
            int tp = t[0];
            if (tp == 1) {
                ll l = t[1], r = t[2], val = t[3];
                auto l_id = l / sz;
                auto r_id = r / sz;
                if (l_id == r_id) {
                    for (int i=l; i<=r; i++) { 
                        int bid = l_id, x = b[i];
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
                        int bid = l_id, x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+val]++;
                        b[i] += val;
                    }
                    for (int i=r_id*sz; i<(r_id+1)*sz; i++) {
                        if (i > r || i < 0) continue;
                        int bid = r_id, x = b[i];
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