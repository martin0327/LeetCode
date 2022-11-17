class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1) * (ay2-ay1);
        int area2 = (bx2-bx1) * (by2-by1);
        int xlo = max(ax1,bx1);
        int xhi = min(ax2,bx2);
        int ylo = max(ay1,by1);
        int yhi = min(ay2,by2);
        
        if (xlo >= xhi) return area1 + area2;
        if (ylo >= yhi) return area1 + area2;
        
        return area1 + area2 - (xhi-xlo) * (yhi-ylo);        
    }
};