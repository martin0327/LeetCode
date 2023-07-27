using ll = long long;
using vi = vector<ll>;
using i128 = __int128;

class Solution {
public:
    int minSpeedOnTime(vector<int>& a, double hour) {
        string s;
        {
            int cnt = -1;
            for (auto c : to_string(hour)) {
                if (c == '.' || cnt >= 0) cnt++;
                if (c != '.') s += c;
                if (cnt >= 2) break;
            }
        }
        ll mul = 1e9, n = a.size();
        i128 temp = (i128) stoll(s) * mul;
        ll h = temp / 100;
        ll lo = 1, hi = 1e7, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            ll cum = 0;
            for (int i=0; i<n-1; i++) {
                cum += mul*((a[i]+mid-1)/mid);
            }
            cum += (mul*a.back()/mid);
            if (cum <= h) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};