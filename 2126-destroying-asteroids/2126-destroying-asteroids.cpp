class Solution {
public:
    bool asteroidsDestroyed(int b, vector<int>& a) {
        long long c = b;
        sort(a.begin(), a.end());
        for (auto x : a) {
            if (x <= c) {
                c += x;
            }
            else {
                return false;
            }
        }
        return true;
    }
};