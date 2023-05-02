class Solution {
public:
    int arraySign(vector<int>& a) {
        bool res = false;
        for (auto &x : a) {
            if (!x) return 0;
            res ^= (x<0);
        }
        return res?-1:1;
    }
};