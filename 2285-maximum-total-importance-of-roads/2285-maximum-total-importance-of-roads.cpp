using ll = long long;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) { 
        vector<ll> deg(n);
        for (auto v : roads) {
            ll x = v[0];
            ll y = v[1];
            deg[x]++;
            deg[y]++;
        }
        sort(deg.begin(), deg.end());
        ll ans = 0;
        for (int i=0; i<n; i++) {
            ll x = i+1;
            ans += x * deg[i];
        }
        return ans;
    }
};