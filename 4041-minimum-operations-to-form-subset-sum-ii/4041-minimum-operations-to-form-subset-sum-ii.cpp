using pii = pair<int,int>;
using vp = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;
const int sz = 501;
const int m = 5001;
const int inf = 2e9;
int weight[sz][m];
vp tr[sz];
void chmin(int &x, int y) { x = min(x,y); }

void debug(vp a) {
    for (auto [x,y] : a) {
        cout << x << " " << y << endl;
    }
}

class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        if (tr[1].empty()) {
            for (int i=1; i<sz; i++) {
                for (int j=0; j<m; j++) {
                    weight[i][j] = inf;
                }
                weight[i][0] = 0;
                for (int l=0,x=i; x>0; l++) {
                    weight[i][x] = l;
                    x >>= 1;
                }
                for (int j=1; j<m; j++) {
                    if (weight[i][j] < inf) {
                        if (2*j < m) {
                            chmin(weight[i][2*j], weight[i][j]+1);
                        }
                        tr[i].push_back({j,weight[i][j]});
                    }
                }
            }
        }
        int n = a.size();
        // vvi dp(n+1, vi(k+1, inf));
        vi dp(k+1, inf);
        dp[0] = 0;
        for (int i=0; i<n; i++) {
            for (int j=k; j>=0; j--) {
                if (dp[j] == inf) continue;
                for (auto [x,w] : tr[a[i]]) {
                    int nj = j + x;
                    if (nj <= k) {
                        chmin(dp[nj], dp[j] + w);
                    }
                }
            }
        }
        auto ans = dp[k];
        if (ans == inf) ans = -1;
        return ans;
    }
};