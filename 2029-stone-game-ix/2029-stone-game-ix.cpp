using vi = vector<int>;
class Solution {
public:
    bool stoneGameIX(vector<int>& a) {
        vi c(3);
        for (auto x : a) c[x%3]++;
        
        auto f = [&] (int x, int y, int z) {
            bool ret = false;
            if (x == 0) return ret;
            if (y == 0) {
                if (x < 3) return ret;
                return ret = z&1;
            }
            if (x == 1) return ret = (z+1)&1;
            x -= 2;
            auto mn = min(x,y);
            x -= mn;
            y -= mn;
            if (max(x,y) == 0) return ret;
            if (x > 0) return ret = z&1; 
            else {
                if (y <= 1) return ret;
                return ret = (z+1)&1;
            }
            return false;
        };
        if (f(c[1],c[2],c[0])) return true;
        if (f(c[2],c[1],c[0])) return true;
        return false;
    }
};