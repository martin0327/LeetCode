using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:    
  vi primes;
  vi is_prime;
  void init_primes(int n) {
    is_prime.assign(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i=2; i<=n; i++) {
      if (is_prime[i]) {
        primes.push_back(i);
        for (int j=2*i; j<=n; j+=i) {
          is_prime[j] = 0;
        }
      }
    }
  }
  vector<int> closestPrimes(int left, int right) {
    init_primes(right+1);
    int n = primes.size();
    vi ans = {-1,-1};
    int min_diff = 1e9;
    for (int i=1; i<n; i++) {
      int x = primes[i-1];
      int y = primes[i];
      if (left <= x && y <= right) {
        if (y-x < min_diff) {
          ans = {x,y};
          min_diff = y-x;
        }
      }
    }
    return ans;
  }
};  