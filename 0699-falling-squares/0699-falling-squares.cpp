template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }

template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }

template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}

template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using vi = vector<int>;
using pii = pair<int,int>;
using vp = vector<pii>;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& a) {
        vi cx;
        vp b;
        for (auto &v : a) {
            int l = v[0], r = v[1];
            r += l;
            cx.push_back(l);
            cx.push_back(r);
            b.push_back({l,r});
        }
        cx = get_unique(cx);
        int sz = cx.size();
        auto g = [&] (int x) {
            auto it = lower_bound(cx.begin(), cx.end(),x);
            return it - cx.begin();
        };

        vi d(sz), ans;
        for (auto [l,r] : b) {
            int len = r-l;
            l = g(l), r = g(r);
            int mx = 0;
            for (int j=l; j<r; j++) {
                chmax(mx, d[j]);
            }
            for (int j=l; j<r; j++) {
                d[j] = mx + len;
            }
            for (int j=0; j<sz; j++) {
                chmax(mx, d[j]);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};