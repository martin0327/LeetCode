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

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<int,int,int>;
using vti3 = vector<ti3>;
using vs = vector<string>;


class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oi, int s, int e) {
        e++;
        vp a;
        for (auto &v : oi) {
            int l = v[0], r = v[1] + 1;
            a.push_back({l,r});
        }
        asort(a);
        vp b;
        for (auto [l,r] : a) {
            if (b.empty()) {
                b.push_back({l,r});
            }
            else {
                if (b.back().second >= l) {
                    chmax(b.back().second, r);
                }
                else b.push_back({l,r});
            }
        }
        // debug(b);
        vp res;
        for (auto [l,r] : b) {
            if (max(l,s) >= min(r,e)) {
                res.push_back({l,r});
            }
            else {
                if (min(l,s) == s && max(r,e) == e) continue;
                else if (min(l,s) == l && max(r,e) == r) {
                    res.push_back({l,s});
                    res.push_back({e,r});
                }
                else {
                    if (min(l,s) == l) {
                        res.push_back({l,s});
                    }
                    else {
                        res.push_back({e,r});
                    }
                }
            }
        }
        // debug(res);
        vector<vector<int>> ans;
        for (auto [l,r] : res) {
            if (l > r-1) continue;
            ans.push_back({l,r-1});
        }
        return ans;
    }
};