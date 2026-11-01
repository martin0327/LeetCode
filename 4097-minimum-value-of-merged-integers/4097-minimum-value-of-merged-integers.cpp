class Solution {
public:
    int minMergedInteger(vector<int>& a) {
        int n = a.size(), ans = 2e9;
        for (int i=1; i<n; i+=2) {
            auto x = to_string(a[i-1]);
            auto y = to_string(a[i]);
            ans = min(ans, stoi(x + y));
        }
        return ans;
    }
};