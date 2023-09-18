using pii = pair<int,int>;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        vector<pii> b;
        for (int i=0; i<n; i++) {
            int cnt = 0;
            for (int j=0; j<m; j++) {
                if (a[i][j]) cnt++;
                else break;
            }
            b.emplace_back(cnt,i);
        }
        sort(b.begin(), b.end());
        vector<int> ans(k);
        for (int i=0; i<k; i++) ans[i] = b[i].second;
        return ans;        
    }
};