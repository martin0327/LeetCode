class Solution {
public:
    int splitArray(vector<int>& a, int m) {
        using ll = long long;
        int n = a.size();
        ll lo = 0;
        ll hi = 1e9;
        int ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            int cur = 0;
            int cnt = 1;
            bool ok = true;
            for (auto x : a) {
                if (x > mid) ok = false;
                
                if (cur+x>mid) {
                    cur = x;
                    cnt++;
                }
                else {
                    cur += x;
                }
            }
            if (cnt>m) ok = false;
            if (ok) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans;        
    }
};