using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        ll lo = -2e9, hi = 2e9, t = 2e9+1;
        while (lo <= hi) {
            ll mid = (lo+hi) / 2;
            ll cnt = 0;
            for (auto x : a) {
                cnt += (upper_bound(b.begin(), b.end(), mid-x) - b.begin());
            }
            if (cnt >= k) {
                hi = mid - 1;
                t = mid;
            }
            else lo = mid + 1;
        }
        vector<tuple<int,int,int>> temp;
        for (auto x : a) {
            for (auto y : b) {
                if (x+y <= t) temp.emplace_back(x+y,x,y);
                else break;
            }
        }
        sort(temp.begin(), temp.end());
        while (temp.size() > k) temp.pop_back();
        vector<vector<int>> ans;
        for (auto [w,x,y] : temp) {
            ans.push_back({x,y});
        }
        return ans;
    }
};

