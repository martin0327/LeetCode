template<typename T>
int popcount(T x) {return __builtin_popcountll(x);}
class Solution {
public:
    int calculateScore(int a, int b) {
        int x = popcount(a);
        int y = popcount(b);
        if (x >= y) return x*y;
        else return y / x;
    }
};