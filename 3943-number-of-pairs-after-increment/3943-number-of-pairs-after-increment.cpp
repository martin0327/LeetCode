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
            int bid = i / sz, x = b[i];
            frq[bid][x]++;
        }

        vi ans;
        for (auto &t : qr) {
            int tp = t[0];
            if (tp == 1) {
                ll l = t[1], r = t[2], v = t[3];
                int left = l / sz, right = r / sz;
                if (left == right) {
                    for (int i=l; i<=r; i++) { 
                        int bid = left, &x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+=v]++;
                    }
                }
                else {
                    for (int bid=left+1; bid<right; bid++) {
                        offset[bid] += v;
                    }
                    for (int j=0; j<sz; j++) {
                        int i = left*sz+j;
                        if (i < l || i >= n) continue;
                        int bid = left, &x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+=v]++;
                    }
                    for (int j=0; j<sz; j++) {
                        int i = right*sz+j;
                        if (i > r) break;
                        int bid = right, &x = b[i];
                        frq[bid][x]--;
                        frq[bid][x+=v]++;
                    }
                }
            }
            else {
                ll tot = t[1], cnt = 0;
                for (int bid=0; bid<m; bid++) {
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