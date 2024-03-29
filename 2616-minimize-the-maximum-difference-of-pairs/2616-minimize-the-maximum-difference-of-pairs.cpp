class Solution {
public:
    int minimizeMax(vector<int>& a, int p) {
        int n = a.size();
        sort(a.begin(), a.end());
        int lo = 0, hi = 1e9, ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int cnt = 0;
            for (int i=0; i<n-1; i++) {
                if (a[i+1]-a[i]<=mid) {
                    cnt++;
                    i++;
                }
            }
            if (cnt >= p) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};