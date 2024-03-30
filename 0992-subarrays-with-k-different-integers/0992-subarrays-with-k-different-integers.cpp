class Solution {
public:
    using vi = vector<int>;
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n = a.size();
        vi c(n+1);
        int cnt = 0, ans = 0;
        vi max_left(n+1, -1);
        vi min_left(n+1, -1);
        for (int i=0, j=0; i<n; ) {
            if (cnt == k) {
                if (min_left[j] == -1) min_left[j] = i;
            }
            if (j < n && cnt <= k) {
                if (++c[a[j++]]==1) cnt++;
            }
            else {
                if (--c[a[i++]]==0) cnt--;
            }
        }
        for (int i=0, j=0; j<=n; ) {
            while (cnt > k) {
                if (--c[a[i++]] == 0) cnt--;
            }
            while (cnt == k) {
                if (c[a[i]] > 1) {
                    --c[a[i++]];
                }
                else break;
            }
            if (cnt == k) {
                max_left[j] = i;
            }
            if (j==n) break;
            if (j < n && cnt <= k) {
                if (++c[a[j++]]==1) cnt++;
            }
        }
        for (int i=0; i<=n; i++) {
            if (min_left[i] == -1) continue;
            if (max_left[i] == -1) continue;
            int l = min_left[i];
            int r = max_left[i];
            ans += r-l+1;
        }
        return ans;
    }
};