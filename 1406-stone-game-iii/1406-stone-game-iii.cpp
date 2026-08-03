using ll = long long;
using vi = vector<int>;
const int inf = 1e9;
const int sz = 5e4+5;
int dp[sz][2];
bool vis[sz][2];
int pre[sz];
int n;

int f(int i, int j) {
    if (i >= n) return 0;
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = 1;
    int ret = (j&1) ? inf : -inf;
    for (int d=1; d<=3; d++) {
        int ni = i + d;
        if (ni > n) continue;
        if (j&1) ret = min(ret, f(ni,j^1));
        else ret = max(ret,f(ni,j^1) + pre[ni]-pre[i]);
    }
    return dp[i][j] = ret;
}

class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        n = a.size();
        for (int i=0; i<n; i++) {
            pre[i+1] = pre[i] + a[i];
        }
        memset(vis,0,sizeof(vis));
        
        
        // function<int(int,int)> f = [&](int i, int j) {
        //     if (i >= n) return 0;
        //     if (vis[i][j]) return dp[i][j];
        //     vis[i][j] = 1;
    
        //     int ret = (j&1) ? inf : -inf;
        //     for (int d=1; d<=3; d++) {
        //         int ni = i + d;
        //         if (ni > n) continue;
        //         if (j&1) ret = min(ret, f(ni,j^1));
        //         else ret = max(ret,f(ni,j^1) + pre[ni]-pre[i]);
        //     }
        //     return dp[i][j] = ret;
        // };
        int s = f(0,0);
        if (2*s == pre[n]) return "Tie";
        else if (2*s > pre[n]) return "Alice";
        else return "Bob";
    }
};