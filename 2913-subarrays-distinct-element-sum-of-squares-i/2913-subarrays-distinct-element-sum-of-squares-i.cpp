class Solution {
public:
    int sumCounts(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int i=0; i<n; i++) {
            set<int> s;
            for (int j=i; j<n; j++) {
                s.insert(a[j]);
                int sz = s.size();
                ans += sz*sz;
            }
        }
        return ans;
    }
};