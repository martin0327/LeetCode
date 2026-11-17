using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;

void chmin(int &x, int y) {x = min(x,y);}

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        s = ' ' + s;
        
        vvi div(n+1);
        for (int l=1; l<=n; l++) {
            for (int d=1; d<l; d++) {
                if (l % d == 0) div[l].push_back(d);
            }
        }
        
        vvi a(n+1, vi(n+1,inf));
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                int l = j-i+1;
                string t = s.substr(i,l);
                int res = inf;
                for (auto m : div[l]) {
                    int cnt = 0;
                    vector<string> b(m);
                    for (int i=0; i<l; i++) {
                        b[i%m] += t[i];
                    }
                    for (auto &t : b) {
                        int sz = t.size();
                        for (int i=0; i<sz/2; i++) {
                            if (t[i] != t[sz-1-i]) cnt++;
                        }
                    }
                    res = min(res, cnt);
                }
                a[i][j] = res;
            }
        }
        
        vvi dp(n+1, vi(k+1,inf));
        dp[0][0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<k; j++) {
                for (int l=i+1; l<=n; l++) {
                    chmin(dp[l][j+1], dp[i][j]+a[i+1][l]);
                }
            }
        }
        return dp[n][k];
    }
};