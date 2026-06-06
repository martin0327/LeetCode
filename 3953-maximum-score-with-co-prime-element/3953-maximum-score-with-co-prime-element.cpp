
template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}
template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;

vi mu;
vi primes;
vi is_prime;
const int sz = 1e5+1;
class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
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

        vi a(nums.begin(), nums.end());
        int n = a.size();
        auto mx = *max_element(a.begin(), a.end());
        chmax(mx, maxVal);
        mx++;
        // int sz = 10;
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
                b[j] += -mu[i] * mul[i];
            }
        }
        b[1] = n;

        ll ans = -2e9;
        for (int i=1; i<mx; i++) {
            ll cost = b[i];
            if (frq[i] > 0 && cost > 0) cost--;
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