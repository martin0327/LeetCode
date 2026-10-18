
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
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;
using vvs = vector<vs>;
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
            chmax(m, r+1);
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
            for (auto r : b[i]) {
                pq.push(r);
            }
            if (a[i] > 0 && lim <= i) {
                if (pq.size()) {
                    auto r = pq.top();
                    if (r > i) {
                        lim = r;
                        pq.pop();
                        ans++;
                    }
                    else {
                        return -1;
                    }
                }
                else return -1;
            }
        }
        return ans;
    }
};