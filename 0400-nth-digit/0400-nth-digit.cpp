using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9) return n;
        n--;
        vi a = {1};
        while (a.back() < 2e9) {
            a.push_back(a.back() * 10);
        }
        for (auto x : a) {
            ll sz = to_string(x).size();
            ll y = 9 * x * sz;
            if (n >= y) n -= y;
            else {
                ll q = n / sz;
                ll r = n % sz;
                auto ans = to_string(x+q)[r] - '0';
                return ans;
            }
        }
        return 0;
    }
};