class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s1 = (ax2-ax1) * (ay2-ay1);
        int s2 = (bx2-bx1) * (by2-by1);
        int dx = min(ax2,bx2) - max(ax1,bx1);
        int dy = min(ay2,by2) - max(ay1,by1);
        return s1 + s2 - max(dx,0) * max(dy,0);
    }
};