void chmin(short &x, short y) { x = min(x,y); }
class Solution {
public:
    int earliestFinishTime(vector<int>& at, vector<int>& ad, vector<int>& bt, vector<int>& bd) {
        short n = at.size(), m = bt.size(), ans = 1<<14;
        for (short i=0; i<n; i++) {
            short x = at[i] + ad[i];
            for (short j=0; j<m; j++) {
                short y = bt[j] + bd[j];
                chmin(ans, (x<=bt[j])?y:x+bd[j]);
                chmin(ans, (y<=at[i])?x:y+ad[i]);
            }
        }
        return ans;
    }
};