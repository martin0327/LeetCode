class Solution {
public:
    bool canReach(string s, int lo, int hi) {
        int n = s.size();
        vector<int> a = {0};
        for (int i=1; i<n; i++) {
            if (s[i] == '1') continue;
            auto it = lower_bound(a.begin(), a.end(), i-hi);
            if (it != a.end() && *it <= i-lo) a.push_back(i);
        }
        return a.back() == n-1;
    }
};