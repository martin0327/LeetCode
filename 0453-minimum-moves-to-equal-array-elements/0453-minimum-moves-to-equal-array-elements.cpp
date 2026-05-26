using ll = long long;
class Solution {
public:
    int minMoves(vector<int>& a) {
        auto mn = *min_element(a.begin(), a.end());
        int ans = 0;
        for (auto x : a) ans += x - mn;
        return ans;
    }
};