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
    asort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using vi = vector<int>;
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

const int sz = 1e5+5;
vi pf[sz];
int frq[sz];
class Solution {
public:
    int longestSubarray(vector<int>& a, int k) {
        if (primes.empty()) {
            init_spf(sz);
        }
        int n = a.size();
        for (int i=0; i<n; i++) {
            auto g = get_pfactors(a[i]);
            pf[i] = get_unique(g);
        }
        int lo = 1, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int cnt = 0;
            memset(frq,0,sizeof(frq));
            for (int i=0; i<mid; i++) {
                for (auto p : pf[i]) {
                    if (++frq[p] == 1) cnt++;
                }
            }
            bool ok = cnt <= k;
            for (int i=mid; i<n; i++) {
                for (auto p : pf[i]) {
                    if (++frq[p] == 1) cnt++;
                }
                for (auto p : pf[i-mid]) {
                    if (--frq[p] == 0) cnt--;
                }
                if (cnt <= k) ok = true;
            }
            if (ok) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;
    }
};