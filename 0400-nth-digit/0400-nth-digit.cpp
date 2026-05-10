using ll = long long;
using vi = vector<ll>;
vi a;
class Solution {
public:
    int findNthDigit(int n) {
        if (a.empty()) {
            a = {1};
            while (a.back() < 2e9) {
                a.push_back(a.back() * 10);
            }
        }
        
        if (n <= 9) return n;
        n--;
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