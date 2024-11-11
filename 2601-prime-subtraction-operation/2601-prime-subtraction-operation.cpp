using vi = vector<int>;

void debug(vi &a) {
    for (auto x : a) {
        cout << x << " " ;
    }
    cout << endl;
}

class Solution {
public:
    bool primeSubOperation(vector<int>& a) {
        int n = a.size(), mx = 1000;
        vi is_prime(mx+1,1), primes;
        for (int i=2; i<=mx; i++) {
            if (!is_prime[i]) continue;
            primes.push_back(i);
            for (int j=i*i; j<=mx; j+=i) {
                is_prime[j] = 0;
            }
        }
        reverse(primes.begin(), primes.end());
        bool ans = true;
        for (int i=0; i<n; i++) {
            for (auto p : primes) {
                if (p < a[i] && (i==0 || a[i-1] < a[i] - p)) {    
                    a[i] -= p;
                    break;
                }
            }
            if (i > 0 && a[i] <= a[i-1]) ans = false;
        }
        return ans;
    }
};