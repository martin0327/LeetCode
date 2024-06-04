class Solution {
public:
    int countDays(int k, vector<vector<int>>& a) {
        int n = a.size();
        vector<pair<int,int>> b(n);
        for (int i=0; i<n; i++) {
            b[i] = {a[i][0],a[i][1]};
        }
        sort(b.begin(), b.end());
        vector<pair<int,int>> c;
        for (auto [l,r] : b) {
            if (c.empty() || l > c.back().second) c.push_back({l,r});
            else c.back().second = max(c.back().second, r);
        }
        int ans = k;
        for (auto [l,r] : c) {
            ans -= (r-l+1);
        }
        return ans;
    }
};

// 1   2   3   4   5   6   7   8   9   10
// [       ]       [       ]       [    ]
    
    
    