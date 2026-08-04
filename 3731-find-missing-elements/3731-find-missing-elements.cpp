class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
        auto [l,r] = minmax_element(a.begin(), a.end());
        set<int> s(a.begin(), a.end());
        vector<int> ans;
        for (int i=*l; i<*r; i++) {
            if (!s.count(i)) ans.push_back(i);
        }
        return ans;
    }
};