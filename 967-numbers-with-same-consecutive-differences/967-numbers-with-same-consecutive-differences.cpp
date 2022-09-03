class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if (k==0) {
            vector<int> ret;
            for (int i=1; i<=9; i++) {
                string s(n,'0'+i);
                ret.push_back(stoi(s));
            }
            return ret;
        }
        vector<int> a;
        for (int i=1; i<=9; i++) a.push_back(i);
        for (int i=0; i<n-1; i++) {
            vector<int> b;
            for (auto x : a) {
                vector<int> c = {x%10+k, x%10-k};
                for (auto y : c) {
                    if (y < 0 || y > 9) continue;
                    b.push_back(10*x+y);
                }
            }
            a = b;
        }
        return a;
    }
};