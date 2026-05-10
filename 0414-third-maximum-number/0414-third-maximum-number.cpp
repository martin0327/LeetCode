class Solution {
public:
    int thirdMax(vector<int>& a) {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int sz = a.size();
        if (sz < 3) return a.back();
        return a[sz-3];
    }
};