using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int largestVariance(string s) {
        ll n = s.size(), ans = 0, inf = 1e9;
        s.insert(s.begin(), ' ');

        vvi nxt(n+1, vi(26,inf));
        for (int i=n; i>0; i--) {
            for (int j=0; j<26; j++) {
                if (s[i]=='a'+j) nxt[i-1][j] = i;
                else nxt[i-1][j] = nxt[i][j];
            }
        }

        for (int x=0; x<26; x++) {
            for (int y=0; y<26; y++) {
                if (x==y) continue;
                vi b(n+1,-inf);
                ll mx = (s[1]=='a'+x) ? -1 : -inf;
                ll c1 = 0, c2 = 0;
                for (int i=1; i<=n; i++) {
                    mx = max(mx, b[i]);
                    ll nx = nxt[i][x];
                    if (nx < inf) b[nx] = max(b[nx],c1-c2);
                    if (s[i]-'a'==x && i > 1) c1++;
                    if (s[i]-'a'==y) c2++;
                    ans = max(ans, c2-c1+mx);
                }
            }
        }
        return ans; 
    }
};