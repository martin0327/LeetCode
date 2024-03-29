using ll = long long;
using vi = vector<ll>;

vi b;

class Solution {
public:
    long long minimumCost(vector<int>& a) {
        if (b.empty()) {
            for (int i=1; i<10; i++) b.push_back(i);
            for (int i=1; i<=99999; i++) {
                string s = to_string(i);
                if (s.size() > 1) {
                    string t = s.substr(0,s.size()-1);
                    reverse(t.begin(), t.end());
                    b.push_back(stoll(s+t));
                }

                string t = s;
                reverse(t.begin(), t.end());
                b.push_back(stoll(s+t));

            }
            sort(b.begin(), b.end());
        }
        sort(a.begin(), a.end());        
        ll n = a.size(), m = b.size(), ans = 2e18; 
        ll cur = accumulate(a.begin(), a.end(), 0ll);

        ll l = 0, r = n;
        for (ll i=0, j=0; j<m; j++) {
            ll d = 0, acc = 0;
            while (i < n && a[i] < b[j]) {
                acc += a[i++];
                d++;
            }
            cur -= 2*acc;
            l += d;
            r -= d;
            ll t = cur + l*b[j] - r*b[j];
            ans = min(ans, t);
        }
        return ans;
    }
};