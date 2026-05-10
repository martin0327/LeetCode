template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
const int sz = 1e5+1;
bool check[sz];
class Solution {
public:
    long long minArraySum(vector<int>& a) {
        int n = a.size();
        memset(check, 0, sizeof(check));
        for (auto x : a) check[x] = 1;
        vi to(sz,sz);
        for (int i=1; i<sz; i++) {
            if (!check[i]) continue;
            for (int j=i; j<sz; j+=i) chmin(to[j],i);
        }
        ll ans = 0;
        for (auto x : a) ans += to[x];
        return ans;
    }
};