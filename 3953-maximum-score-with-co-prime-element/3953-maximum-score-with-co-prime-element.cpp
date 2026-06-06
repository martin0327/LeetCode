template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using vi = vector<int>;
using vvi = vector<vi>;
vi mu, primes, is_prime;
const int sz = 1e5+1, inf = 2e9;
class Solution {
public:
    int maxScore(vector<int>& a, int maxVal) {
        if (mu.empty()) {
            mu = vi(sz);
            is_prime = vi(sz, true);

            mu[1] = 1;
            is_prime[0] = is_prime[1] = false;
            for (int i=2; i<sz; i++) {
                if (is_prime[i]) {
                    primes.push_back(i);
                    mu[i] = -1;
                }
                for (int p : primes) {
                    if (i * p >= sz) break;
                    is_prime[i*p] = false;
                    if (i%p == 0) {
                        mu[i*p] = 0;
                        break;
                    } 
                    else {
                        mu[i*p] = -mu[i];
                    }
                }
            }
        }

        int n = a.size();
        auto mx = *max_element(a.begin(), a.end());
        chmax(mx, maxVal);
        mx++;
        vi frq(mx);
        for (auto x : a) frq[x]++;
        vi mul(mx);
        for (int i=1; i<mx; i++) {
            for (int j=i; j<mx; j+=i) {
                mul[i] += frq[j];
            }
        }
        
        vi b(mx);
        for (int i=2; i<mx; i++) {
            for (int j=i; j<mx; j+=i) {
                b[j] -= mu[i] * mul[i];
            }
        }
        b[1] = n;

        int ans = -inf;
        for (int i=1; i<mx; i++) {
            int cost = b[i];
            if (frq[i] > 0) {
                if(cost > 0) cost--;
            } 
            else {
                if (cost == 0) cost++;
            }
            if (frq[i] > 0 || i <= maxVal) {
                chmax(ans, i-cost);
            }
        }
        return ans;
    }
};