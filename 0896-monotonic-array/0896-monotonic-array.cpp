class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        auto b = a;
        sort(b.begin(), b.end());
        auto c = b;
        reverse(c.begin(), c.end());
        if (a==b || a==c) return true;
        else return false;
    }
};