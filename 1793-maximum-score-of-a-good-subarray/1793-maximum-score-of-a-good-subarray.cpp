class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int n = a.size();
        map<int, int> mpl, mpr;
        set<int> s;
        {
            int x = a[k];
            for (int i=k; i>=0; i--) {
                x = min(x, a[i]);
                mpl[x] = i;
                s.insert(x);
            }
            x = a[k];
            for (int i=k; i<n; i++) {
                x = min(x, a[i]);
                mpr[x] = i;
                s.insert(x);
            }
        }
        int ans = 0;
        for (auto x : s) {
            auto itl = mpl.lower_bound(x);
            auto itr = mpr.lower_bound(x);
            int l = itl->second;
            int r = itr->second;
            ans = max(ans, (r-l+1) * x);
        }
        return ans; 
    }
};