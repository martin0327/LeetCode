template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 2e18;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        int n = a.size();
        auto f = [&] () {
            vi b(a.begin(), a.end());
            vi c(a.begin(), a.end());
            for (int i=0; i<n; i++) {
                if (i&1) b[i] *= -1;
                else c[i] *= -1;
            }
            vi p1(n+1), p2(n+1);
            for (int i=0; i<n; i++) {
                p1[i+1] = p1[i] + b[i];
                p2[i+1] = p2[i] + c[i];
            }
            ll odd = inf, even = inf;
            ll ans = -inf;
            for (int i=0; i<=n; i++) {
                chmax(ans,p1[i]-even);
                chmax(ans,p2[i]-odd);
                if (i&1) chmin(odd, p2[i]);
                else chmin(even, p1[i]);
            }
            return ans;
        };

        auto g = [&] () {
            vi b(a.begin(), a.end());
            vi c(a.begin(), a.end());
            for (int i=0; i<n; i++) {
                if (i&1) b[i] *= -1;
                else c[i] *= -1;
            }
            b.insert(b.begin(), 0);
            c.insert(c.begin(), 0);
            vi p1(n+2), s1(n+2);
            vi p2(n+2), s2(n+2);
            for (int i=1; i<=n; i++) {
                p1[i] = p1[i-1] + b[i];
                p2[i] = p2[i-1] + c[i];
            }
            for (int i=n; i>=1; i--) {
                s1[i] = s1[i+1] + c[i];
                s2[i] = s2[i+1] + b[i];
            }
            vi L1(n+2,-inf), R1(n+2,-inf);
            vi L2(n+2,-inf), R2(n+2,-inf);
            for (int i=0,even=inf,odd=inf; i<=n; i++) {
                chmax(L1[i],p1[i]-even);
                chmax(L2[i],p2[i]-odd);
                if (i%2==0) chmin(even,p1[i]);
                else chmin(odd,p2[i]);
            }
            for (int i=n+1,mn1=inf,mn2=inf; i>=1; i--) {
                chmax(R1[i],s1[i]-mn1);
                chmax(R2[i],s2[i]-mn2);
                chmin(mn1,s1[i]);
                chmin(mn2,s2[i]);
            }
            ll ans = -inf;
            for (int i=2; i<n; i++) {
                auto x = L1[i-1] + R1[i+1];
                auto y = L2[i-1] + R2[i+1];
                chmax(ans, max(x,y));
            }
            return ans;
        };
        auto x = f();
        auto y = g();
        return max(x,y);
    }
};