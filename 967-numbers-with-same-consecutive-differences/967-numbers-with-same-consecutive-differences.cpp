class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> a;
        for (int i=1; i<=9; i++) a.insert(i);
        for (int i=0; i<n-1; i++) {
            set<int> b;
            for (auto x : a) {
                vector<int> c = {x%10+k, x%10-k};
                for (auto y : c) {
                    if (y < 0 || y > 9) continue;
                    b.insert(10*x+y);
                }
            }
            a = b;
        }
        vector<int> ret;
        for (auto x : a) ret.push_back(x);
        return ret;
    }
};