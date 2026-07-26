template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}
using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& a, vector<vector<int>>& b) {
        vi c;
        for (auto &v : a) c.push_back(v[0]);
        for (auto &v : b) c.push_back(v[0]);
        c = get_unique(c);
        vvi ans;
        for (auto &x : c) {
            vi tg = {x,0};
            auto it1 = lower_bound(a.begin(), a.end(), tg);
            auto it2 = lower_bound(b.begin(), b.end(), tg);
            int s = 0;
            if (it1 != a.end()) s += (*it1)[1];
            if (it2 != b.end()) s += (*it2)[1];
            vi t = {x,s};
            ans.push_back(t);
        }
        return ans;
    }
};