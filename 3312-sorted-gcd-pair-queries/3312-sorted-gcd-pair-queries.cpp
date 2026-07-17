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
    vector<int> gcdValues(vector<int>& aa, vector<long long>& qr) {
        vi a(aa.begin(), aa.end());
        ll sz = 5e4 + 1;
        vi frq(sz);
        for (auto x : a) {
            frq[x]++;
        }
        vi b(sz);
        for (int i=1; i<sz; i++) {
            for (int j=i; j<sz; j+=i) {
                b[i] += frq[j];
            }
        }
        for (int i=sz-1; i>0; i--) {
            b[i] = b[i] * (b[i]-1) / 2;
            for (int j=2*i; j<sz; j+=i) {
                b[i] -= b[j];
            }
        }
        vi pre(sz);
        for (int i=1; i<sz; i++) {
            pre[i] = pre[i-1] + b[i];
        }
        vector<int> ans;
        for (auto q : qr) {
            q++;
            ll lo = 0, hi = sz-1, res = -1;
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                if (pre[mid] >= q) {
                    res = mid;
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};