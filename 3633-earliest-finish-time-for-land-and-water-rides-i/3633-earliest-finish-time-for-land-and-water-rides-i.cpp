class Solution {
public:
    int earliestFinishTime(vector<int>& at, vector<int>& ad, vector<int>& bt, vector<int>& bd) {
        int n = at.size(), m = bt.size(), ans = 2e9;
        for (int i=0; i<n; i++) {
            int x = at[i] + ad[i];
            for (int j=0; j<m; j++) {
                int y = bt[j] + bd[j];

                if (x <= bt[j]) ans = min(ans, y);
                else ans = min(ans, x + bd[j]);
                if (y <= at[i]) ans = min(ans, x);
                else ans = min(ans, y + ad[i]);
            }
        }
        return ans;
    }
};