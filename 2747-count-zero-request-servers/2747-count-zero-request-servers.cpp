template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}
using vi = vector<int>;
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int len, vector<int>& qr) {
        vi cx;
        map<int,vi> t2i, off;
        for (auto &v : logs) {
            auto i = v[0], t = v[1];
            cx.push_back(t);
            cx.push_back(t+len+1);
            t2i[t].push_back(i);
        }
        int q = qr.size();
        for (int i=0; i<q; i++) {
            auto &t = qr[i];
            off[t].push_back(i);
            cx.push_back(t);
        }
        cx = get_unique(cx);
        int sz = cx.size(), cur = 0;
        vi cnt(n+1), ans(q);
        for (int i=0; i<sz; i++) {
            auto t = cx[i];
            for (auto id : t2i[t]) {
                cnt[id]++;
                if (cnt[id] == 1) cur++;
            }
            auto p = t-len-1;
            if (t2i.count(p)) {
                for (auto id : t2i[p]) {
                    cnt[id]--;
                    if (cnt[id] == 0) cur--;
                }
            }
            for (auto idx : off[t]) {
                ans[idx] = n - cur;
            }
        }
        return ans;
    }
};