using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    vector<int> gcdValues(vector<int>& a, vector<long long>& qr) { 
        int sz = *max_element(a.begin(), a.end()) + 1;
        vi b(sz);
        for (auto x : a) b[x]++;
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
        for (int i=1; i<sz; i++) b[i] += b[i-1];
        vector<int> ans;
        for (auto x : qr) {
            auto it = lower_bound(b.begin(), b.end(), x+1);
            ans.push_back(it-b.begin());
        }
        return ans;
    }
};