class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<int> ans(n,-1);
        for (int i=0; i<n; i++) {
            int x = a[i];
            for (int j=0, flag = false; j<m; j++) {
                if (b[j] == x) flag = true;
                if (flag && b[j] > x) {
                    ans[i] = b[j];
                    break;
                }
            }
        }
        return ans;
    }
};