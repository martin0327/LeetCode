vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};

class Solution {
public:
    vector<int> cnt;
    int int_pow(int base, int exp) {
        int res = 1;
        while (exp) {
            if (exp & 1) res *= base;
            exp >>= 1;
            base *= base;
        }
        return res;
    }
    void f(int n) {
        for (int i=2; i<=n; i++) {
            int x = i;
            for (auto p : primes) {
                while (x % p == 0) {
                    x /= p;
                    cnt[p]++;
                }
                if (x==1) break;
            }
        }
    }
    void g(int n) {
        for (int i=2; i<=n; i++) {
            int x = i;
            for (auto p : primes) {
                while (x % p == 0) {
                    x /= p;
                    cnt[p]--;
                }
                if (x==1) break;
            }
        }
    }
    
    int uniquePaths(int m, int n) {
        cnt = vector<int>(200);
        f(n+m-2);
        g(n-1);
        g(m-1);
        int ans = 1;
        for (auto p : primes) {
            int c = cnt[p];
            if (c>0) ans *= int_pow(p,c);
        }
        return ans;
    }
};