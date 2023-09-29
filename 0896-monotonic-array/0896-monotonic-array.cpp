class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        bool b1 = 0, b2 = 0;
        for (int i=1; i<a.size(); i++) {
            if (a[i]>a[i-1]) b1 = true;
            if (a[i]<a[i-1]) b2 = true;
            if (b1&&b2) return false;
        }
        return true;
    }
}; 