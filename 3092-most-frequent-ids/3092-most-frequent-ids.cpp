using ll = long long;
const ll sz = 1e5;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<ll> cnt(sz+1), ans(n);
        priority_queue<pair<ll,ll>> pq;
        for (int i=0; i<n; i++) {
            cnt[a[i]] += b[i];
            pq.push({cnt[a[i]],a[i]});
            while (pq.size()) {
                auto [c,x] = pq.top();
                if (c == cnt[x]) {
                    ans[i] = c;
                    break;
                }
                else pq.pop();
            }
        }
        return ans;
    }
};