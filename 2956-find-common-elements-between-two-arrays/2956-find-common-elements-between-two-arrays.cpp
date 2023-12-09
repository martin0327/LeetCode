class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& a, vector<int>& b) {
        set<int> s1(a.begin(),a.end()), s2(b.begin(), b.end());
        vector<int> ans(2);
        for (auto x : a) if (s2.count(x)) ans[0]++;
        for (auto x : b) if (s1.count(x)) ans[1]++;
        return ans;
    }
};