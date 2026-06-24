using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
const int sz = 26;
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        ll n = s.size(), cur = 0;
        vi a(n,1);
        for (int i=1; i<n; i++) {
            int x = s[i] - 'a';
            int y = s[i-1] - 'a';
            if (x == (y+1) % sz) a[i] = a[i-1] + 1;
        }
        set<pii> sp;
        for (int i=0; i<n; i++) {
            sp.insert({a[i], s[i] - 'a'});
        }
        set<pii> t;
        for (auto [x,y] : sp) {
            for (int i=x; i>=1; i--) {
                if (t.count({i,y})) break;
                else t.insert({i,y});
            }
        }
        int ans = t.size();
        return ans;
    }
}; 