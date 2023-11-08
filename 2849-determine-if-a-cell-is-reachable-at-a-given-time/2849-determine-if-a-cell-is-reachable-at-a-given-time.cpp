using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        ll dx = abs(sx-fx);
        ll dy = abs(sy-fy);
        ll d = max(dx,dy);
        if (d==0) return t != 1;
        else return d <= t; 
    }
};