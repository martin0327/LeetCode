class Solution {
public:
    vector<int> missingRolls(vector<int>& a, int mean, int n) {
        int m = a.size(), s = mean * (n+m);
        int t = accumulate(a.begin(),a.end(),0);
        int d = s - t;
        if (n <= d && d <= 6*n) {
            vector<int> ans(n,1);
            d -= n;
            int q = d / n;
            int r = d % n;
            for (int i=0; i<n; i++) {
                if (i < r) ans[i] += q+1;
                else ans[i] += q;
            }
            return ans;
        }
        else return {};        
    }
};