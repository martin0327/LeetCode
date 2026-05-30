class Solution {
public:
    vector<int> findValidElements(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        for (int i=0; i<n; i++) {
            int lmx = 0, rmx = 0, x = a[i];
            for (int j=0; j<n; j++) {
                if (j < i) lmx = max(lmx, a[j]);
                if (j > i) rmx = max(rmx, a[j]);
            }
            if (x > lmx || x > rmx) ans.push_back(x);
        }
        return ans;
    }
};