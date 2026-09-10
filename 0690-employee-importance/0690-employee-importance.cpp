using vi = vector<int>;
class Solution {
public:
    int getImportance(vector<Employee*> emp, int id) {
        int sz = 2001;
        vector<Employee*> a(sz);
        vi vis(sz);
        queue<int> q;
        for (auto e : emp) {
            int i = e->id;
            a[i] = e;
            if (id == i) {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (q.size()) {
            auto u = q.front();
            q.pop();
            for (auto nb : a[u]->subordinates) {
                int v = a[nb]->id;
                if (vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }
        int ans = 0;
        for (int i=0; i<sz; i++) {
            if (vis[i]) {
                ans += a[i]->importance;
            }
        }
        return ans;
    }
};