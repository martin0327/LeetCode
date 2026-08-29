class Solution {
public:
    vector<string> largestString(vector<int>& a) {
        int n = a.size(), sz = 26;
        vector<string> ans(n);
        for (int i=0; i<n; i++) {
            auto x = a[i];
            string s;
            for (int j=sz-1; j>=0; j--) {
                int y = 1<<j;
                while (x >= y) {
                    x -= y;
                    s += 'a' + j;
                }
            }
            ans[i] = s;
        }
        return ans;
    }
};