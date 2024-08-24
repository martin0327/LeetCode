using ll = long long;
class Solution {
public:
    string nearestPalindromic(string s) {
        ll x = stoll(s), n = s.size(), diff = 2e18;
        ll ans = 0;
        auto f = [&] (string t) {
            ll y = stoll(t);
            ll d = abs(x-y);
            if (d < diff && d > 0) {
                ans = y;
                diff = d;
            }
        };

        {
            string t(n+1,'0');
            t.front() = t.back() = '1';
            f(t);
        }
        if (n > 1) {
            string t(n-1, '9');
            f(t);
        }
        {
            string t = s;
            for (int i=0; i<n/2; i++) {
                t[n-1-i] = t[i];
            }
            for (int i=0; i<10; i++) {
                ll u = n/2;
                t[u] = t[n-1-u] = '0' + i;
                
                if (n>2) {
                    for (int j=0; j<10; j++) {
                        ll v = n/2-1;
                        t[v] = t[n-1-v] = '0' + j;
                        f(t);
                    }
                }
                else f(t);
            }
        }
        if (s.front() > '1') {
            string t(n,'9');
            t.front() = t.back() = s.front()-1;
            f(t);
        }
        return to_string(ans);        
    }
};