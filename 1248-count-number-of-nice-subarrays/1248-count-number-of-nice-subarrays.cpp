class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n = a.size();
        set<int> s = {-1, n};
        for (int i=0; i<n; i++) {
            if (a[i]&1) s.insert(i);
        }
        int ans = 0;
        if (s.size() < k+2) return ans;
        for (auto i = s.begin(), j = s.begin(); *j < n; ) {
            if (i == s.begin()) {
                i++; 
                int t = k;
                while (t--) {
                    j++;
                }
            }
            int l = *i - *prev(i);
            int r = *next(j) - *j;
            ans += l * r;
            i++; j++;
        }
        return ans;
    }
};