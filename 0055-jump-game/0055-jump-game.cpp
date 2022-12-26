class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int sup = 0;
        for (int i=0; i<n; i++) {
            if (i <= sup) {
                sup = max(sup, i + a[i]);
            }
            else return false;
        }
        return true;
    }
};