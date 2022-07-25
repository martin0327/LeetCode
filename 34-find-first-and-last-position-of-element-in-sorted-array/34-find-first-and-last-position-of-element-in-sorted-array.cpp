class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        vector<int> ret(2);
        auto it = lower_bound(a.begin(), a.end(), t);
        if (it == a.end() || *it != t) ret[0] = -1;
        else ret[0] = it - a.begin();
        it = upper_bound(a.begin(), a.end(), t);
        if (it == a.begin() || *prev(it) != t) ret[1] = -1;
        else ret[1] = prev(it) - a.begin();
        return ret;
    }
};