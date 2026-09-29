class Solution {
public:
    int reachNumber(int tg) {
        tg = abs(tg);
        for (int i=1,x=0;;i++) {
            x += i;
            int d = x - tg;
            if (d >= 0 && d%2 == 0) return i;
        }
        return -1;
    }
};