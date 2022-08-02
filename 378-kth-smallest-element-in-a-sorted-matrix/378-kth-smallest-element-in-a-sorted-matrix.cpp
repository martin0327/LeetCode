class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n = a.size();
        int lo = -1e9;
        int hi = 1e9;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int cnt = 0;
            for (auto &b : a) {
                auto it = upper_bound(b.begin(), b.end(), mid);
                cnt += it - b.begin();
            }
            if (cnt >= k) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;  
    }
};