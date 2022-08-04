class Solution {
public:
    int mirrorReflection(int p, int q) {
        int cur = 0;
        int lr = 0;
        int ud = 0;
        int cnt = 0;
        while (true) {
            cur += q;
            lr = (lr+1)&1;
            if (cur > p) ud = (ud+1)&1;
            cur %= p;
            if (cur==0) {
                if (ud&1) {
                    if (lr==1) return 0;
                }
                else {
                    if (lr==1) return 1;
                    else return 2;
                }
            }
        }
        return 0;
    }
};