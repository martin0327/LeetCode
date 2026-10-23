class Solution {
public:
    int sortPermutation(vector<int>& a) {
        int n = a.size();
        auto b = a;
        sort(b.begin(), b.end());
        vector<int> c;
        for (int i=0; i<n; i++) {
            if (a[i] != b[i]) c.push_back(a[i]);
        }
        if (c.empty()) return 0;
        int ans = c[0];
        for (auto x : c) ans &= x;
        return ans;   
    }
};