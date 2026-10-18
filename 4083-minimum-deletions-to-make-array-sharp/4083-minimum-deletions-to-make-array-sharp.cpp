class Solution {
public:
    int minDeletions(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int i=1; i<n; i++) {
            if (a[i] == a[i-1]) ans++;
        }
        // vector<int> b;
        // for (auto x : a) {
        //     if (b.empty() || b.back() != x) {
        //         b.push_back(x);
        //     }
        //     else ans++;
        // }
        return ans;
    }
};