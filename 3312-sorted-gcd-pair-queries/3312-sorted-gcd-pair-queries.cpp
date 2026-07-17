using ll = long long;
using vi = vector<ll>;
const int sz = 5e4+1;
ll b[sz];
class Solution {
public:
    vector<int> gcdValues(vector<int>& a, vector<long long>& qr) { 
        memset(b,0,sizeof(b));
        for (auto x : a) {
            b[x]++;
        }
        for (int i=1; i<sz; i++) {
            for (int j=2*i; j<sz; j+=i) {
                b[i] += b[j];
            }
        }
        for (int i=sz-1; i>0; i--) {
            b[i] = b[i] * (b[i]-1) / 2;
            for (int j=2*i; j<sz; j+=i) {
                b[i] -= b[j];
            }
        }
        for (int i=1; i<sz; i++) {
            b[i] += b[i-1];
        }
        vector<int> ans;
        for (auto q : qr) {
            q++;
            ll lo = 0, hi = sz-1, res = -1;
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                if (b[mid] >= q) {
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