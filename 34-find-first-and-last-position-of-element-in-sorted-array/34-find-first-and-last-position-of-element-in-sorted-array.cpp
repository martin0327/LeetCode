class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        vector<int> ret;
        auto it = lower_bound(a.begin(), a.end(), t);
        if (it == a.end() || *it != t) ret.push_back(-1);
        else ret.push_back(it - a.begin());
        it = upper_bound(a.begin(), a.end(), t);
        if (it == a.begin() || *prev(it) != t) ret.push_back(-1);
        else ret.push_back(prev(it) - a.begin());
        return ret;
    }
};