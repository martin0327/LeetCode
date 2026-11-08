template <class T> std::vector<int> z_algorithm(const std::vector<T>& s) {
    int n = int(s.size());
    if (n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        int& k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string& s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) {
        s2[i] = s[i];
    }
    return z_algorithm(s2);
}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = 2e18;
class Solution {
public:
    vector<int> countSuffix(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        auto ab = a;
        ab.push_back(inf);
        for (auto x : b) ab.push_back(x);
        auto z = z_algorithm(ab);
        unordered_map<int,int> frq_a, frq;
        for (auto x : a) frq_a[x]++;

        int cur = 0, dec = 1, unq_a = frq_a.size();
        for (int i=0; i<n; i++) {
            auto x = b[i];
            if (frq_a.count(x)) {
                frq[x]++;
                if (frq[x] == frq_a[x]) cur++;
                if (frq[x] == frq_a[x]+1) cur--;
            }
            if (i > 0) {
                if (b[i] <= b[i-1]) dec++;
                else dec = 1;
            }
        }
        vi valid(m);
        valid[n-1] = cur == unq_a;
        for (int i=n; i<m; i++) {
            auto x = b[i];
            if (frq_a.count(x)) {
                frq[x]++;
                if (frq[x] == frq_a[x]) cur++;
                if (frq[x] == frq_a[x]+1) cur--;
            }
            auto y = b[i-n];
            if (frq_a.count(y)) {
                frq[y]--;
                if (frq[y] == frq_a[y]) cur++;
                if (frq[y] == frq_a[y]-1) cur--;
            }
            valid[i] = cur == unq_a;
        }
        vector<int> ans;
        for (int i=n-1; i<m; i++) {
            if (i >= n) {
                if (b[i] <= b[i-1]) dec++;
                else dec = 1;
            }
            if (valid[i]) {
                auto l = z[i+2];
                auto r = dec;
                ll lo = 1, hi = min(r,n), res = hi+1;
                while(lo <= hi) {
                    auto mid = (lo+hi)/2;
                    if (mid + l >= n) {
                        res = mid;
                        hi = mid - 1;
                    }
                    else lo = mid + 1;
                }
                ans.push_back(min(n,r)-res+1);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};