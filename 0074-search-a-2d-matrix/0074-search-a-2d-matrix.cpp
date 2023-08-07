class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto v : matrix) {
            for (auto x : v) {
                if (x==target) return true;
            }
        }
        return false;
    }
};