using ll = long long;
const int sz = 5e4+1;
ll b[sz];
vector<int> ans;
class Solution {
public:
    vector<int> gcdValues(vector<int>& a, vector<long long>& qr) { 
        memset(b,0,sizeof(b));
        int sz = 0, q = qr.size();
        for (auto x : a) {
            b[x]++;
            sz = max(sz, x+1);
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
        for (int i=1; i<sz; i++) b[i] += b[i-1];
        
        ans.resize(q);
        for (int i=0; i<q; i++) {
            auto it = lower_bound(b,b+sz,qr[i]+1);
            ans[i] = it - b;
        }
        return ans;
    }
};