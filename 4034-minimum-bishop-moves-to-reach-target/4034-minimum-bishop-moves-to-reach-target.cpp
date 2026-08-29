class Solution {
public:
    int minBishopMoves(vector<int>& src, vector<int>& tg) {
        int sr = src[0], sc = src[1];
        int tr = tg[0], tc = tg[1];
        if ((sr+sc)%2 != (tr+tc)%2) return -1;
        if ((sr+sc) == (tr+tc)) return 1;
        if ((sr-sc) == (tr-tc)) return 1;
        return 2;
    }
};