using ll = long long;
using vi = vector<ll>;
vi a;
class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (a.empty()) {
            a = {0,1};
            while (a.back() < 1e9) {
                a.push_back(a.back() + a[a.size()-2]);
            }
        }
        int m = a.size();
        for (int i=2; i<m; i++) {
            auto x = a[i] + a[i-1] + a[i-2];
            if (x == n) return true;
        }
        return false;
    }
};