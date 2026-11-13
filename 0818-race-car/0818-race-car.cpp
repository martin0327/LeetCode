template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

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

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;


class Solution {
public:
    int racecar(int tg) {
        pii src = {0,1};
        map<pii,int> dp;
        dp[src] = 0;
        queue<pii> q;
        q.push(src);
        while (q.size()) {
            auto [u,v] = q.front();
            auto d = dp[{u,v}];
            q.pop();
            {
                int nu = u + v;
                int nv = 2 * v;
                if (nu == tg) return d+1;
                if (abs(nu) <= 2*tg) {
                    pii nxt = {nu,nv};
                    if (!dp.count(nxt)) {
                        dp[nxt] = d + 1;
                        q.push(nxt);
                    }
                } 
            }
            {
                int nu = u;
                int nv = (v > 0) ? -1 : 1;
                pii nxt = {nu,nv};
                if (!dp.count(nxt)) {
                    dp[nxt] = d + 1;
                    q.push(nxt);
                }
            }
        }
        return -1;
    }
};
