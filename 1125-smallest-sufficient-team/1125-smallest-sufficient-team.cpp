using vi = vector<int>;
using ti3 = tuple<int,int,int>;
const int inf = 1e9;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {    
        int m = 0;
        map<string,int> mp;
        for (auto s : req_skills) {
            mp[s] = m++;
        }
        int n = people.size();
        vi a(n);
        for (int i=0; i<n; i++) {
            for (auto s : people[i]) {
                a[i] |= (1<<mp[s]);
            }
        }
        vector<ti3> dp(1<<m, {inf,-1,-1});
        dp[0] = {0,-1,-1};
        for (int i=0; i<n; i++) {
            for (int mask=(1<<m)-1; mask>=0; mask--) {
                auto [y,pi,pm] = dp[mask];
                if (y==inf) continue;
                int nmask = mask | a[i];
                auto [z,ni,nm] = dp[nmask];
                if (y+1 < z) {
                    dp[nmask] = {y+1,i,mask};
                }
            }
        }
        auto [val,i,mask] = dp[(1<<m)-1];
        vi ans = {i};
        while (mask > 0) {
            auto [v,i,nmask] = dp[mask];
            ans.push_back(i);
            mask = nmask;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};