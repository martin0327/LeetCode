using vi = vector<int>;
using pii = pair<int,int>;
using vp = vector<pii>;
void chmin(int &x, int y) { x = min(x,y); }

class Solution {
public:
    int earliestFinishTime(vector<int>& at, vector<int>& ad, vector<int>& bt, vector<int>& bd) {
        int n = at.size(), m = bt.size(), ans = 2e9;
        vp a(n), b(m);
        vi c(n), d(m);
        for (int i=0; i<n; i++) {
            a[i] = {at[i],ad[i]};
            c[i] = {at[i]+ad[i]};
        }
        for (int i=0; i<m; i++) {
            b[i] = {bt[i],bd[i]};
            d[i] = {bt[i]+bd[i]};
        }
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        for (int i=0; i<n; i++) {
            auto it = upper_bound(d.begin(), d.end(), at[i]);
            if (it != d.begin()) chmin(ans, at[i] + ad[i]);
            else chmin(ans, *it + ad[i]);
        }
        for (int i=0; i<m; i++) {
            auto it = upper_bound(c.begin(), c.end(), bt[i]);
            if (it != c.begin()) chmin(ans, bt[i] + bd[i]);
            else chmin(ans, *it + bd[i]);
        }
        return ans;
    }
};