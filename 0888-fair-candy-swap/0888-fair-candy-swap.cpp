class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        auto sa = accumulate(a.begin(), a.end(), 0);
        auto sb = accumulate(b.begin(), b.end(), 0);
        int d = (sa-sb)/2;
        set<int> s(b.begin(), b.end());
        for (auto x : a) {
            if (s.count(x-d)) return {x,x-d};
        }
        return {-1,-1};
    }
};