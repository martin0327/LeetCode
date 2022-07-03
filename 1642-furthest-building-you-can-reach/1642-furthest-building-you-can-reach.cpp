class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        int n = a.size();
        
        int ans = -1;
        int lo = 0, hi = n-1;
        
        vector<pair<int,int>> c(n);
        for (int i=1; i<n; i++) {
            c[i] = {max(a[i]-a[i-1],0), i};
        }
        sort(c.rbegin(), c.rend());
        
        while (lo <= hi) {
            int mid = (lo+hi) / 2;
            
            int s = 0;
            int cnt = 0;
            for (auto [d,i] : c) {
                if (i > mid) continue;
                if (cnt < l) cnt++;
                else s += d;
            }
            
            if (s <= b) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;        
        
    }
};