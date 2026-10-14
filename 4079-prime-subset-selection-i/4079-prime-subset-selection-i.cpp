using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
vi primes;
vi spf; 
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

vi get_pfactors(int x) {
    vi ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        if (primes.empty()) {
            int sz = 1e6 + 1;
            init_spf(sz);
        }
        ll cum = 0;
        vector<int> ans;
        for (auto p : primes) {
            if (p > n) break;
            cum += p;
            if (cum > s) break;
            ans.push_back(p);
        }
        return ans;
    }
};