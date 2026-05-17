using ll = long long;
using i128 = __int128;

struct rabin_karp {
    size_t n;
    i128 B, P;                          // base and modulus for this instance
    inline static const i128 defaultP = (1ll << 61) - 1;


    std::vector<i128> pw;               // pw[i] = B^i mod P
    std::vector<i128> h;                // prefix hashes

    // --- helper: get a random base in [1000, sqrt(P)] ---
    static i128 random_base(i128 P) {
        return 2587934;
    }

    // --- helper for string → vector<int> ---
    static std::vector<int> to_vec(const std::string &s) {
        std::vector<int> a(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            a[i] = (unsigned char)s[i];
        }
        return a;
    }

    // --- core constructor: explicit base + modulus ---
    rabin_karp(const std::vector<int> &a, i128 B, i128 P = defaultP)
        : n(a.size()), B(B), P(P), pw(n + 1, 1), h(n + 1, 0) {

        // pw[i] = B^i mod P
        for (int i = 1; i <= (int)n; i++) {
            pw[i] = (pw[i - 1] * B) % P;
        }

        // backward-style prefix hash:
        // h[i+1] = h[i]*B + a[i]   (mod P)
        for (int i = 0; i < (int)n; i++) {
            h[i+1] = ((h[i] * B )%P + a[i]) % P;
        }
    }

    // --- convenience constructor: random base, given modulus (or defaultP) ---
    rabin_karp(const std::vector<int> &a, i128 P = defaultP)
        : rabin_karp(a, random_base(P), P) {}

    // --- string constructor: explicit base B, explicit P ---
    rabin_karp(const std::string &s, i128 B, i128 P)
        : rabin_karp(to_vec(s), B, P) {}

    // --- convenience constructor: random base, given modulus (or defaultP) ---
    rabin_karp(const std::string &s, i128 P = defaultP)
        : rabin_karp(to_vec(s), random_base(P), P) {}

    // hash of substring [l, r] (0-indexed, inclusive)
    i128 query(int l, int r) const {
        assert(0 <= l && l <= r && (size_t)r < n);
        int len = r - l + 1;

        // x = h[r+1] - h[l] * B^len
        i128 x = h[r + 1] - ( (__int128)h[l] * pw[len] ) % P;
        x %= P;
        if (x < 0) x += P;
        return x;
    }

    // optional helpers if you want to inspect parameters
    i128 base() const { return B; }
    i128 mod()  const { return P; }
};

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& a) {
        ll n = a.size();
        ll lo = 1, hi = n, ans = -1;
        auto rk = rabin_karp(a);
        map<i128,int> mp;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            mp.clear();
            for (int i=0; i+mid-1<n; i++) {
                mp[rk.query(i,i+mid-1)]++;
            }
            bool ok = false;
            for (auto &[k,v] : mp) {
                if (v == 1) ok = true;
            }
            if (ok) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};