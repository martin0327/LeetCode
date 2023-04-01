class Solution {
public:
    int minNumber(vector<int>& a, vector<int>& b) {
        set<int> s1(a.begin(), a.end());
        set<int> s2(b.begin(), b.end());
        for (auto x : s1) {
            if (s2.count(x)) return x;
        }
        int x = *s1.begin();
        int y = *s2.begin();
        if (x > y) swap(x,y);
        int ans = 10*x + y;
        return ans;
    }
};