using ll = long long;
class Solution {
public:
    int minProcessingTime(vector<int>& a, vector<int>& t) {
        sort(a.begin(), a.end());
        sort(t.begin(), t.end());
        ll ans = 0;
        for (auto x : a) {
            ll y = x + t.back();
            for (int i=0; i<4; i++) t.pop_back();
            ans = max(ans, y);
        }
        return ans;
    }
};