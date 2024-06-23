using ll = long long;
using pii = pair<ll,ll>;
template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    int longestSubarray(vector<int>& a, int lim) {
        ll n = a.size(), lo = 1, hi = n, ans = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            min_pq<pii> pq1;
            max_pq<pii> pq2;
            
            for (int i=0; i<mid; i++) {
                pq1.emplace(a[i],i);
                pq2.emplace(a[i],i);
            }
            ll diff = pq2.top().first - pq1.top().first;
            for (int i=mid; i<n; i++) {
                pq1.emplace(a[i],i);
                pq2.emplace(a[i],i);
                while (pq1.size()) {
                    auto [x,j] = pq1.top();
                    if (j <= i - mid) pq1.pop();
                    else break;
                }
                while (pq2.size()) {
                    auto [x,j] = pq2.top();
                    if (j <= i - mid) pq2.pop();
                    else break;
                }
                diff = min(diff, pq2.top().first - pq1.top().first);
                if (diff <= lim) break;
            }
            if (diff <= lim) {
                ans = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        assert(ans != -1);
        return ans;
    }
};