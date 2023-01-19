class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n = a.size();
        vector<int> pre(n+1);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i-1];
        int ans = 0;
        map<int,int> mp;
        for (int x : pre) ans += mp[((x%k)+k)%k]++;
        return ans;
    }
};