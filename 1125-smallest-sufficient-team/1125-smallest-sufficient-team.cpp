using ll = int;
using ti3 = tuple<ll,ll,ll>;
using vi = vector<ll>;
const ll inf = 1e9;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string,ll> mp;
        ll m = 0;
        for (auto s : req_skills) {
            if (!mp.count(s)) mp[s] = m++;
        }
        ll n = people.size();
        vi a(n);
        for (int i=0; i<n; i++) {
            for (auto s : people[i]) {
                a[i] |= (1ll<<mp[s]);
            }
        }
        vector<ti3> dp(1<<m, {inf,-1,-1});
        dp[0] = {0,-1,-1};
        for (int i=0; i<n; i++) {
            ll x = a[i];
            for (ll mask=(1ll<<m)-1; mask>=0; mask--) {
                auto [y,pidx,pmask] = dp[mask];
                if (y==inf) continue;
                ll nmask = mask | x;
                auto [z,nidx,_] = dp[nmask];
                if (y+1 < z) {
                    dp[nmask] = {y+1,i,mask};
                }
            }
        }
        auto [val,idx,mask] = dp[(1ll<<m)-1];
        vector<int> ans;
        ans.push_back(idx);
        while (mask > 0) {
            auto [v,i,nmask] = dp[mask];
            ans.push_back(i);
            mask = nmask;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};