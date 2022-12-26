class Solution {
public:
    bool canJump(vector<int>& a) {
        int mx = 0;
        for (int i=0; i<a.size(); i++) {
            if (i <= mx) {
                mx = max(mx, i + a[i]);
            }
            else return false;
        }
        return true;
    }
};   