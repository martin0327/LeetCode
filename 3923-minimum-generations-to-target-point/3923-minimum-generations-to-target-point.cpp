template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;

class Solution {
public:
    int minGenerations(vector<vector<int>>& pt, vector<int>& tg) {
        int idx = 0;
        vti3 a;
        ti3 t = {tg[0], tg[1], tg[2]};
        for (auto &v : pt) {
            int x = v[0], y = v[1], z = v[2];
            ti3 xyz = {x,y,z};
            if (xyz == t) return idx;
            a.push_back(xyz);
        }
        idx++;
        while (true) {
            int sz = a.size();
            vti3 b;
            for (auto [x1,y1,z1] : a) {
                for (auto [x2,y2,z2] : a) {
                    ti3 xyz = {(x1+x2)/2, (y1+y2)/2, (z1+z2)/2};
                    if (xyz == t) return idx;
                    b.push_back(xyz);
                }
            }
            idx++;
            for (auto &xyz : a) b.push_back(xyz);
            b = get_unique(b);
            if (b.size() == sz) break;
            swap(a,b);
        }
        return -1;
    }
};