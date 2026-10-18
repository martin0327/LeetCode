template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;
using vi = vector<int>;
using vvi = vector<vi>;
const int sz = 2e5+5;
int a[sz];

class Solution {
public:
    int minSelection(vector<vector<int>>& av, vector<vector<int>>& tg) {
        memset(a,0,sizeof(a));
        int m = 0;
        for (auto &v : tg) {
            int l = v[0], r = v[1];
            l *= 2;
            r = 2*r+1;
            a[l]++;
            a[r]--;
            m = max(m,r+1);
        }
        for (int i=1; i<m; i++) {
            a[i] += a[i-1];
        }
        max_pq<int> pq;
        int lim = -1, ans = 0;
        vvi b(m);
        for (auto &v : av) {
            int l = v[0], r = v[1];
            l *= 2;
            r = 2*r+1;
            if (l < m) b[l].push_back(r);
        }
        for (int i=0; i<m; i++) {
            for (auto r : b[i]) pq.push(r);
            if (a[i] > 0 && lim <= i) {
                if (pq.size() && pq.top() > i) {
                    lim = pq.top();
                    pq.pop();
                    ans++;
                }
                else return -1;
            }
        }
        return ans;
    }
};