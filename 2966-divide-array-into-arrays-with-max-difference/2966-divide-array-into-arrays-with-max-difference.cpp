class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        vector<vector<int>> b;
        for (auto x : a) {
            if (b.empty() || b.back().size() == 3) b.push_back({x});
            else b.back().push_back(x);
        }
        for (auto c : b) {
            if (c.back()-c.front() > k) return {};
        }
        return b;
    }
};