class Solution {
public:
    int minQueenMoves(vector<int>& src, vector<int>& tg) {
        auto x1 = src[0], y1 = src[1];
        auto x2 = tg[0], y2 = tg[1];
        if (x1 == x2 && y1 == y2) return 0;
        if (x1 == x2 || y1 == y2) return 1;
        if (abs(x1-x2) == abs(y1-y2)) return 1;
        return 2;
    }
};