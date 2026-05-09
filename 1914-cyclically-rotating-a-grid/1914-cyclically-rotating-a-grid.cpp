
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

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        int sz = min(n,m)/2;
        for (int i=0; i<sz; i++) {
            vi rs = {i,n-1-i};
            vi cs = {i,m-1-i};
            vp b;
            for (auto r : rs) {
                for (auto c : cs) {
                    b.push_back({r,c});
                }
            }
            swap(b[1],b[2]);
            swap(b[2],b[3]);
            vp v;
            for (int j=0; j<4; j++) {
                auto [r,c] = b[j];
                auto [tr,tc] = b[(j+1)%4];
                while (r != tr || c != tc) {
                    v.push_back({r,c});
                    int dr = tr - r;
                    int dc = tc - c;
                    if (dr != 0) {
                        r += dr / abs(dr);
                    }
                    if (dc != 0) {
                        c += dc / abs(dc);
                    }
                }
            }

            int sz = v.size();
            vi t(sz);
            for (int i=0; i<sz; i++) {
                auto [r,c] = v[i];
                t[i] = a[r][c];
            }
            for (int i=0; i<sz; i++) {
                auto [r,c] = v[i];
                int j = (i-k)%sz;
                j = (j+sz) % sz;
                a[r][c] = t[j];
            }
        }
        return a;
    }
};