using vi = vector<int>;
void debug(vi &a) {
    for (auto &x : a) cout << x << " ";
    cout << endl;
}
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& a, int lo, int hi) {
        int n = a.size();
        vi L, R;
        for (int i=0; i<n; i++) {
            if (a[i] > hi) R.push_back(i);
            else if (a[i] >= lo) L.push_back(i);
        }
        int ans = 0;
        auto f = [&] (int i, vi &b) {
            auto it = upper_bound(b.begin(), b.end(), i);
            if (it == b.begin()) return -1;
            else return *prev(it);
        };
        for (int i=0; i<n; i++) {
            auto r = f(i,L);
            auto l = f(i,R);
            vi t = {i,l,r};
            if (r > l) ans += r-l;
        }
        return ans;
    }
};