class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        return lower_bound(a.begin(),a.end(),t) - a.begin();
    }
};