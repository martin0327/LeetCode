using ll = long long;
class Solution {
public:
    int minPatches(vector<int>& a, int k) {
        ll cur = 0, ans = 0, n = a.size();
        for (int j=0; ;) {
            if (cur >= k) break;
            while (j<n && a[j]<=cur+1) {
                cur += a[j++];
            }
            if (cur >= k) break;
            if (j>=n || a[j] > cur+1) {
                cur += cur+1;
                ans++;
            }
        }        
        return ans;        
    }
};
