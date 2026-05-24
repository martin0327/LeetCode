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
        int n = b.size(), sz = sqrt(n);
        int num_b = ceil_div(n, sz);
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
                auto left = l / sz;
                auto right = r / sz;
                if (left == right) {
                    for (int i=l; i<=r; i++) { 
                        int bid = left, x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+v]++;
                        b[i] += v;
                    }
                }
                else {
                    for (int bid=left+1; bid<right; bid++) {
                        offset[bid] += v;
                    }
                    for (int i=0; i<sz; i++) {
                        int j = left*sz+i;
                        if (j < l || j >= n) continue;
                        int bid = left, x = b[j];
                        frq[bid][x]--;
                        frq[bid][x+v]++;
                        b[j] += v;
                    }
                    for (int i=right*sz; i<(right+1)*sz; i++) {
                        if (i > r) continue;
                        int bid = right, x = b[i];
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