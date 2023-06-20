class Solution {
public:
    vector<int> getAverages(vector<int>& a, int k) {
        int n = a.size();
        vector<long long> pre(n+1);
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] + a[i-1];
        }
        vector<int> ans;
        for (int i=1; i<=n; i++) {
            if (i-k <= 0 || i+k>n) ans.push_back(-1);
            else {
                int l = i-k-1;
                int r = i+k;
                ans.push_back((pre[r]-pre[l])/(r-l));
            }
        }
        return ans;        
    }
};