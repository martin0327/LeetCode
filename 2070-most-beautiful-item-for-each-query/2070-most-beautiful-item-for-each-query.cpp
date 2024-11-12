using vi = vector<int>;
using pii = pair<int,int>;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& qr) {
        int n = items.size(), q = qr.size();
        
        vector<pii> a(n);
        for (int i=0; i<n; i++) {
            a[i] = {items[i][0], items[i][1]};
        }
        
        sort(a.begin(), a.end());
        
        if (a.size() > 1) {
            for (int i=1; i<n; i++) {
                a[i].second = max(a[i-1].second, a[i].second);
            }

        }
        
        vi ans(q);
        for (int i=0; i<q; i++) {
            int val = qr[i];
            int lo = 0;
            int hi = n-1;
            
            int idx = -1;
            while (lo<=hi) {
                int mid = (lo + hi) / 2;
                // debug(mid);
                
                if (a[mid].first <= val) {
                    idx = mid;
                    lo = mid + 1;                    
                }
                else {
                    hi = mid - 1;
                }
            }
            if (idx == -1) {
                ans[i] = 0;
            }
            else {
                ans[i] = (a[idx].second);                
            }
            
        }
        return ans;
    }
};