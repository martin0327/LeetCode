class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        int n = a.size();
        for (int i=1; i+1<n; i++) {
            if (a[i]&1) {
                int x = a[i-1], y = a[i+1];
                if ((x&1) && (y&1)) return true;
            }
        }
        return false;
    }
};