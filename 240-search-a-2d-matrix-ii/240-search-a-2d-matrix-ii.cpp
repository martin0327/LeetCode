class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto &a : matrix) {
            auto it = lower_bound(a.begin(), a.end(), target);
            if (it != a.end() && *it == target) return true;
        }
        return false;
    }
};