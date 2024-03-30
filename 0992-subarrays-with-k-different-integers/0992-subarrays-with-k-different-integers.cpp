template<typename T>
void chmax(T &x, T y) {x = max(x,y);}

template<typename T>
void chmin(T &x, T y) {x = min(x,y);}


class Solution {
public:
    using vi = vector<int>;
    int subarraysWithKDistinct(vector<int>& a, int k) {

        int n = a.size();
        vi c(n+1);
        int cnt = 0, ans = 0;
        map<int,int> mx, mn;
        for (int i=0, j=0; i<n; ) {
            if (cnt == k) {
                // if (!mx.count(j)) mx[j] = i;
                // else chmax(mx[j],i);
                if (!mn.count(j)) mn[j] = i;
                else chmin(mn[j],i);
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
                if (!mx.count(j)) mx[j] = i;
                else chmax(mx[j],i);
            }
            if (j==n) break;
            if (j < n && cnt <= k) {
                if (++c[a[j++]]==1) cnt++;
            }
            // else {
            //     if (--c[a[i++]]==0) cnt--;
            // }
        }
        // debug(mx);
        // debug(mn);
        set<int> rr;
        for (auto [k,v] : mx) rr.insert(k);
        for (auto [k,v] : mn) rr.insert(k);
        for (auto j : rr) {
            int l = mn[j];
            int r = mx[j];
            ans += r-l+1;
        }

        return ans;
    }
};