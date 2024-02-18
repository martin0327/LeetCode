template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        using ll = long long;
        using pii = pair<ll,ll>;
        using vp =  vector<pii>;

        vp a;
        for (auto x : meetings) {
            a.push_back({x[0],x[1]});
        }

        sort(a.begin(), a.end());

        vector<ll> cnt(n);
        set<ll> rooms;
        for (int i=0; i<n; i++) rooms.insert(i);
        min_pq<pii> pq;

        ll cur = 0;
        for (auto [l,r] : a) {
            cur = max(cur, l);
            while (pq.size()) {
                auto [time,idx] = pq.top();
                if (time<=cur) {
                    rooms.insert(idx);
                    pq.pop();
                }
                else break;
            }
            if (rooms.empty()) {
                auto [cur_time, _] = pq.top();
                cur = cur_time;
                while (pq.size()) {
                    auto [time,idx] = pq.top();
                    if (time==cur_time) {
                        rooms.insert(idx);
                        pq.pop();
                    }
                    else break;
                }
            }
            ll idx = *rooms.begin();
            rooms.erase(idx);
            pq.push({cur+(r-l),idx});
            cnt[idx]++;
        }
        vp cnt2(n);
        for (int i=0; i<n; i++) {
            cnt2[i] = {cnt[i],-i};
        }
        sort(cnt2.rbegin(), cnt2.rend());
        int ans = -cnt2[0].second;
        return ans;
    }
};