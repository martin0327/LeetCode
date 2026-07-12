class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        auto f = [&] (string s) {
            int ret = 0;
            for (int i=0, mul = 3600; i<3; i++) {
                auto t = s.substr(3*i,2);
                ret += mul * stoi(t);
                mul /= 60;
            }
            return ret;
        };
        auto x = f(st), y = f(et);
        return y - x;
    }
};