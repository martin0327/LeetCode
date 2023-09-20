class Solution {
public:
    int minimumRightShifts(vector<int>& a) {
        auto b = a;
        sort(b.begin(), b.end());
        for (int i=0; i<a.size(); i++) {
            if (a==b) return i;
            a.insert(a.begin(), a.back());
            a.pop_back();
        }
        return -1;
    }
};