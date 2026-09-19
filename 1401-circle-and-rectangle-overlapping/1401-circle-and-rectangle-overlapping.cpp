using vi = vector<int>;
using pii = pair<int,int>;
using vp = vector<pii>;
bool in(int x, int l, int r) {
    return l <= x && x <= r;
}
int sq(int x) { return x*x; }
int dsq (pii p1, pii p2) {
    auto [x1,y1] = p1;
    auto [x2,y2] = p2;
    return sq(x1-x2) + sq(y1-y2);
}

class Solution {
public:
    bool checkOverlap(int R, int xc, int yc, int x1, int y1, int x2, int y2) {
        if (in(xc,x1,x2) && in(yc,y1,y2)) return true;
        vi xs = {x1,x2}, ys = {y1,y2};
        pii ct = {xc, yc};
        vp pts;
        auto check = [&] (pii xy) {
            return dsq(ct,xy) <= sq(R);
        };
        for (auto x : xs) {
            for (auto y : ys) {
                pii xy = {x,y};
                pts.push_back(xy);
                if (check(xy)) return true;
            }
        }
        for (int i=0; i<4; i++) {
            auto [x1,y1] = pts[i];
            for (int j=i+1; j<4; j++) {
                auto [x2,y2] = pts[j];
                if (x1 == x2) {
                    if (in(yc,y1,y2)) {
                        pii xy = {x1,yc};
                        if (check(xy)) return true;
                    }
                }
                else {
                    if (in(xc,x1,x2)) {
                        pii xy = {xc,y1};
                        if (check(xy)) return true;
                    }
                }
            }
        }
        return false;
    }
};