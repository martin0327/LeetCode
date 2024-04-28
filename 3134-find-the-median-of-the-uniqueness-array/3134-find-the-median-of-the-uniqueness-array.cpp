using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vi>;
// using vm = vector<mint>;
// using vvm = vector<vm>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        vi a(nums.begin(), nums.end());
        ll n = a.size(), sz = 1e5;
        auto f = [&] (vi &a, ll k) {
            vi cnt(sz+1);
            ll unq = 0, ret = 0;
            for (int i=0, j=0; j<n; ) {
                if (++cnt[a[j++]] == 1) unq++; 
                while (unq >= k) {
                    if (unq > k) {
                        if (--cnt[a[i++]]==0) unq--;
                    } 
                    else {
                        if (cnt[a[i]] == 1) break;
                        else --cnt[a[i++]];
                    }
                }
                if (unq == k) {
                    ret += i+1;
                }
            }
            return ret;
        };

        ll lo = 1, hi = 1e5, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi) / 2;
            ll cnt = f(a, mid);
            ll tot = n*(n+1)/2;
            ll t = tot / 2 + 1;
            if (cnt >= t) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return ans;

    }
};