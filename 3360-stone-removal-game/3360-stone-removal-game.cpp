class Solution {
public:
    bool canAliceWin(int n) {
        for (int x=10; x>=1; x--) {
            if (n >= x) n -= x;
            else return x&1;
        }
        return true;
    }
};