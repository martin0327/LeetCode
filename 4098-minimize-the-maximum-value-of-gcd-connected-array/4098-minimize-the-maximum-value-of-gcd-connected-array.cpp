using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
vi primes, spf; 
void init_spf(int n) {
    spf.resize(n+1);
    for (int i=2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= n; j++) {
            spf[i * primes[j]] = primes[j];
            if (primes[j] == spf[i]) {
                break;
            }
        }
    }
}

class Solution {
public:
    long long minimumMaxValue(int n, int idx, int val) {
        if (primes.empty()) {
            int sz = 1e5;
            init_spf(sz);
        }
        ll min_pf = val;
        {
            auto x = val;
            for (auto p : primes) {
                if (x % p == 0) {
                    min_pf = p;
                    break;
                }
            }
        }
        
        if (val == 1) {
            if (n == 1) return 1;
            else return -1;
        }
        if (val % 2 == 0) {
            if (val / 2 <= idx) {
                return -1;
            }
        }
        else {
            if ((val-min_pf) / 2 <= idx-1) {
                return -1;
            }
        }
        auto d = n-idx-1;
        ll ans = val;
        if (d != 0) {
            if (val % 2 == 0) ans += 2*d;
            else ans += min_pf + 2*(d-1);
        }
        return ans;
    }
};