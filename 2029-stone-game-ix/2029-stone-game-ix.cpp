using vi = vector<int>;
class Solution {
public:
    bool stoneGameIX(vector<int>& a) {
        vi c(3);
        for (auto x : a) c[x%3]++;
        
        auto f = [&] (int x, int y, int z) {
            if (x == 0) return false;
            if (y == 0) {
                if (x < 3) return false;
                return (z+3)%2 == 0;
            }
            if (x == 1) {
                return (z+1)%2 == 1;
            }
            x -= 2;
            auto mn = min(x,y);
            x -= mn;
            y -= mn;
            if (max(x,y) == 0) return false;
            // 1 1 2 1 2 1 2 1
            // 2 2 1 2 1 2 1 2 
            if (x > 0) {
                return (z+1)%2 == 0;
            }
            else {
                if (y <= 1) return false;
                else return ((z+2) % 2) == 0;
            }
            return false;
        };
        if (f(c[1],c[2],c[0])) return true;
        if (f(c[2],c[1],c[0])) return true;
        return false;
    }
};