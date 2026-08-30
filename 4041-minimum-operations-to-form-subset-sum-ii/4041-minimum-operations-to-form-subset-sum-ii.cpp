using pii = pair<int,int>;
using vp = vector<pii>;
const int sz = 501, m = 5001;
const int inf = 2e9;
int weight[sz][m];
int dp[m];
vp tr[sz];
void chmin(int &x, int y) { x = min(x,y); }

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
        for (int j=1; j<=k; j++) dp[j] = inf;
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