using ll = long long;
using vi = vector<int>;
const int mx_sz = 250;

int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}

unordered_map<ll,ll> frq[mx_sz];
ll offset[mx_sz];

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& a, vector<int>& b, vector<vector<int>>& qr) {
        int n = b.size(), sz = sqrt(n);
        int m = ceil_div(n, sz);
        for (int i=0; i<m; i++) {
            frq[i].clear();
        }
        memset(offset, 0, sizeof(offset));

        for (int i=0; i<n; i++) {
            int idx = i / sz, x = b[i];
            frq[idx][x]++;
        }

        vi ans;
        for (auto &t : qr) {
            int tp = t[0];
            if (tp == 1) {
                ll l = t[1], r = t[2], v = t[3];
                int left = l / sz, right = r / sz;
                if (left == right) {
                    for (int i=l; i<=r; i++) { 
                        int idx = left, &x = b[i];
                        frq[idx][x]--;
                        frq[idx][x+=v]++;
                    }
                }
                else {
                    for (int idx=left+1; idx<right; idx++) {
                        offset[idx] += v;
                    }
                    for (int j=0; j<sz; j++) {
                        int i = left*sz+j;
                        if (i < l || i >= n) continue;
                        int idx = left, &x = b[i];
                        frq[idx][x]--;
                        frq[idx][x+=v]++;
                    }
                    for (int j=0; j<sz; j++) {
                        int i = right*sz+j;
                        if (i > r) break;
                        int idx = right, &x = b[i];
                        frq[idx][x]--;
                        frq[idx][x+=v]++;
                    }
                }
            }
            else {
                ll tot = t[1], cnt = 0;
                for (int idx=0; idx<m; idx++) {
                    for (auto x : a) {
                        auto tg = tot - x - offset[idx];
                        if (frq[idx].count(tg)) {
                            cnt += frq[idx][tg];
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
        return ans;
    }
};