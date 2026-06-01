void chmin(int &x, int y) { x = min(x,y); }
class Solution {
public:
    int earliestFinishTime(vector<int>& at, vector<int>& ad, vector<int>& bt, vector<int>& bd) {
        int n = at.size(), m = bt.size(), ans = 2e9;
        for (int i=0; i<n; i++) {
            int x = at[i] + ad[i];
            for (int j=0; j<m; j++) {
                int y = bt[j] + bd[j];
                chmin(ans, (x<=bt[j])?y:x+bd[j]);
                chmin(ans, (y<=at[i])?x:y+ad[i]);
            }
        }
        return ans;
    }
};