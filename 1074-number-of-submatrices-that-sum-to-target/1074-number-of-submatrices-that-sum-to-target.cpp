using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& a, int target) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;
        
        vvi vpre(n+1, vi(m+1));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                vpre[i][j] = vpre[i-1][j] + a[i-1][j-1];
            }
        }
        
        vi pre(m+1);
        for (int i=0; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                for (int k=1; k<=m; k++) {
                    pre[k] = pre[k-1] + vpre[j][k] - vpre[i][k];
                }
                unordered_map<int,int> mp;
                for (auto x : pre) {
                    if (mp.count(x-target)) {
                        ans += mp[x-target];
                    }
                    mp[x]++;
                }
            }
        }
        return ans;
    }
};