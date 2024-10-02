class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        auto b = a;
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (auto &x : a) {
            auto it = lower_bound(b.begin(), b.end(), x);
            x = it - b.begin() + 1;
        }
        return a;
    }
};