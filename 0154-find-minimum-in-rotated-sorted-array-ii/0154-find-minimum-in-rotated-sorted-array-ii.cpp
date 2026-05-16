class Solution {
public:
    int findMin(vector<int>& a) {
        return *min_element(a.begin(), a.end());
    }
};