class Solution {
public:
    int getLargestOutlier(vector<int>& a) {
        int n = a.size(), ans = -1e9, s = 0;
        map<int,vector<int>> mp;
        for (int i=0; i<n; i++) {
            s += a[i];
            mp[a[i]].push_back(i);
        }
        for (int i=0; i<n; i++) {
            int t = s - a[i];
            if (t % 2 == 0) {
                t /= 2;
                if (mp.count(t)) {
                    if (mp[t].size() > 1 || mp[t][0] != i) ans = max(ans, a[i]);
                }
            }
        }
        return ans;        
    }
};