using ll = long long;
class Solution {
public:
    int maxDistance(vector<int>& a, int m) {
        ll n = a.size();
        sort(a.begin(), a.end());
        ll lo = 1, hi = a.back() - a.front(), ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll cur = a[0], cnt = 1;
            for (auto x : a) {
                if (x - cur >= mid) {
                    cur = x;
                    cnt++;
                }
            }
            if (cnt >= m) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};