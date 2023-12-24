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

        ll left = 0, right = n;
        ll i=0, j=0;
        while (j<m) {
            ll d = 0, acc = 0;
            while (i < n && a[i] < b[j]) {
                acc += a[i++];
                d++;
            }
            cur -= 2*acc;
            left += d;
            right -= d;
            ll t = cur + left*b[j] - right*b[j];
            ans = min(ans, t);
            j++;
        }
        return ans;
    }
};