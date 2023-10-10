class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int ans = 1e9;
        for (int i=0; i<a.size(); i++) {
            auto it = upper_bound(a.begin(), a.end(), a[i]+(n-1));
            int cnt = it - a.begin() - i;
            ans = min(ans, n - cnt);
        }

        return ans;        
    }
};