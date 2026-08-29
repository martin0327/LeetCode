template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using vi = vector<int>;
class Solution {
public:
    int maxValidSplits(vector<int>& a) {
        int n = a.size();
        auto f = [&] (vi b) {
            int n = b.size();
            vi pre(n+1), suf(n+2);
            b.insert(b.begin(), 0);
            for (int i=1; i<=n; i++) {
                pre[i] = gcd(pre[i-1],b[i]);
            }
            for (int i=n; i>=1; i--) {
                suf[i] = gcd(suf[i+1],b[i]);
            }
            int res = 0;
            for (int i=1; i+1<=n; i++) {
                auto x = pre[i];
                auto y = suf[i+1];
                if (x == y) res++;
            }
            return res;
        };
        auto ans = f(a);
        for (int i=0; i<n; i++) {
            vi b;
            for (int j=0; j<n; j++) {
                if (i == j) continue;
                b.push_back(a[j]);
            }
            int t = f(b); 
            chmax(ans, t);
        }
        return ans;
    }
};