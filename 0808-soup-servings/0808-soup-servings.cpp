using vd = vector<double>;
using vvd = vector<vd>;

class Solution {
public:
    double soupServings(int n) {
        if (n > 5000) return 1;
        n = (n+24)/25;
        vvd dp(n+1, vd(n+1,-1));
        function<double(int,int)> f = [&](int x, int y) {            
            if (x<=0 && y<=0) return 0.5;
            if (x<=0) return 1.0;
            if (y<=0) return 0.0;
            if (dp[x][y] != -1) return dp[x][y];
            double ret = 0;
            ret += f(x-4,y);
            ret += f(x-3,y-1);
            ret += f(x-2,y-2);
            ret += f(x-1,y-3);
            return dp[x][y] = 0.25*ret;
        };
        double ans = f(n,n);
        return ans;        
        return 0;
    }
};