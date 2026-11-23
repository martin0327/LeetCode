class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& a) {
        for (auto &v : a) {
            reverse(v.begin(), v.end());
            for (auto &x : v) x ^= 1;
        }
        return a;
    }
};