using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
class Solution {
public:
    int uniqueLetterString(string s) {
        ll n = s.size(), ans = 0;
        vvi a(26);
        for (int i=0; i<n; i++) {
            a[s[i] - 'A'].push_back(i);
        }
        for (auto &p : a) {
            int m = p.size();
            for (int i=0; i<m; i++) {
                ll l,r;
                if (i==0) l = p[i]+1;
                else l = p[i] - p[i-1];
                if (i<m-1) r = p[i+1] - p[i];
                else r = n - p[i];
                ans += l*r;
            }
        }
        return ans;
    }
};