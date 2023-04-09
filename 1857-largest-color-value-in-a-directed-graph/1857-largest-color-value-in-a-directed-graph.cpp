using vi = vector<int>;
using vvi = vector<vi>;
void chmax(int &x, int y) {x = max(x,y);}

class Solution {
public:
    int largestPathValue(string c, vector<vector<int>>& edges) {
        int n = c.size();
        vvi adj(n);
        vi deg(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            deg[e[1]]++;
        }
        vvi dp(n, vi(26));
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (deg[i]==0) {
                q.push(i);
                dp[i][c[i]-'a']=1;
            }
        }
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                for (int j=0; j<26; j++) {
                    chmax(dp[v][j], dp[u][j]+((c[v]-'a')==j));
                }
                if (--deg[v]==0) q.push(v);
            }
        }
        if (accumulate(deg.begin(), deg.end(),0)==0) {
            int ret = 0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<26; j++) {
                    chmax(ret,dp[i][j]);
                }
            }
            return ret;
        }
        else return -1;
    }
};