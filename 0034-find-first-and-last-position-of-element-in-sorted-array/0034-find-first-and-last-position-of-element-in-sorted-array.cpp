class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        auto l = lower_bound(a.begin(), a.end(), t);
        auto r = upper_bound(a.begin(), a.end(), t);
        int x = (l != a.end() && *l == t) ? l - a.begin() : -1;
        int y = (r != a.begin() && *prev(r)==t) ? prev(r) - a.begin() : -1;
        return {x,y};
    }
};