class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        short b = 0;
        for (int i=1; i<a.size(); i++) {
            if (a[i]>a[i-1]) b |= 1;
            if (a[i]<a[i-1]) b |= 2;
        }
        return (b==3) ? false : true;
    }
};