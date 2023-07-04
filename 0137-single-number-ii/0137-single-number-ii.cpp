class Solution {
public:
    int singleNumber(vector<int>& a) {
        int x = 0, y = 0;
        for (auto z : a) {
            int t = y & z;
            y &= ~t;
            z &= ~t;
            t = x & z;
            x |= z;
            x &= ~t;
            y |= t;
        }
        return x;
    }
};