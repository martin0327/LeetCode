class Solution {
public:
    int findMaxK(vector<int>& a) {
        int sz = 1001;
        vector<bool> pos(sz), neg(sz);
        for (auto x : a) {
            if (x > 0) pos[x] = 1;
            else neg[-x] = 1;
        }
        for (int i=sz-1; i>=1; i--) {
            if (pos[i] && neg[i]) return i;
        }
        return -1;
    }
};