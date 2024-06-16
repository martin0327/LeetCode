using ll = long long;
class Solution {
public:
    int minPatches(vector<int>& a, int k) {
        ll cur = 1, ans = 0;
        if (a[0] == 1) a.erase(a.begin());
        else ans++;
        ll n = a.size();
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
