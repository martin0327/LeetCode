using pii = pair<int,int>;
class Solution {
public:
    int countDays(int k, vector<vector<int>>& a) {
        int n = a.size();
        vector<pii> b(n);
        for (int i=0; i<n; i++) {
            b[i] = {a[i][0],a[i][1]};
        }
        sort(b.begin(), b.end());
        vector<pii> c; // merged intervals that has no overlaps
        for (auto [l,r] : b) {
            if (c.empty() || c.back().second < l) c.push_back({l,r});
            else c.back().second = max(c.back().second, r);
        }
        int ans = k;
        for (auto [l,r] : c) ans -= (r-l+1);
        return ans;
        
    }
};

// 1   2   3   4   5   6   7   8   9   10
// [       ]       [       ]       [    ]
       // 3               3              2
           
// 10 - (3-1+1) - (7-5+1) - (10-9+1) = 2
           
           
// if all intervals [l,r] are pairwise disjoint , then the "answer = days - sum(r-l+1)"
// 
           
          // [1,4] [3,7] 
// sort all intervals in ascending order of l 
// [1,7]
           
           
//  1   2   3   4   5
           
    // 1 2 3 4 -> they are pairwise different 
           
           
           //   [3,6] [4,8] [4,5]
           // [3,6] + [4,5] = [3,6]
           // [3,6] + [4,8] = [3,8]