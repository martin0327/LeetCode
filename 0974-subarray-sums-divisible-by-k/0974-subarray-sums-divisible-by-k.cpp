class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pre(n+1);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
        int ans = 0;
        map<int,int> mp;
        for (auto x : pre) {
            int y = ((x%k)+k)%k;
            ans += mp[y];
            mp[y]++;
        }
        return ans;
    }
};