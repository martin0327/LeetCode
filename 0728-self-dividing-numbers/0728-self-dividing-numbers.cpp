class Solution {
public:
    vector<int> selfDividingNumbers(int l, int r) {
        auto f = [&] (int x) {
            auto s = to_string(x);
            for (auto &ch : s) {
                int y = ch - '0';
                if (y == 0) return false;
                if (x % y != 0) return false;
            }
            return true;
        };
        vector<int> ans;
        for (int i=l; i<=r; i++) {
            if (f(i)) ans.push_back(i);
        }
        return ans;
    }
};