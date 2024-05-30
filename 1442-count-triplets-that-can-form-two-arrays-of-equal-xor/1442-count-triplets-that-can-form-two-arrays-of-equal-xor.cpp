class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n+1);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] ^ a[i-1];
        int ans = 0;
        map<int,int> sum, cnt;
        for (int i=2; i<=n; i++) {
            sum[pre[i-2]] += i-1;
            cnt[pre[i-2]] += 1;
            ans += i*cnt[pre[i]] - sum[pre[i]];
        }
        return ans;
    }
};