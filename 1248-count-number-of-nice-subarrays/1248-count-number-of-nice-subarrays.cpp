class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        vector<int> b = {-1};
        for (int i=0; i<n; i++) {
            if (a[i]&1) b.push_back(i);
        }
        b.push_back(n);
        if (b.size() < k+2) return ans;
        for (auto i = b.begin()+1, j = b.begin()+k; *j < n; i++, j++) {
            ans += (*i - *prev(i)) * (*next(j) - *j);
        }
        return ans;
    }
};