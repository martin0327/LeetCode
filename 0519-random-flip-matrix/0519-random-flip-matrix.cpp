mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using vi = vector<int>;
int cnt_leq_x(vi &a, int x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}
class Solution {
public:
    int sz,n,m;
    vector<int> a;
    Solution(int n, int m) {
        this->n = n;
        this->m = m;
        sz = n*m;
    }
    
    vector<int> flip() {
        int x = rng() % sz;
        sz--;
        int lo = 0, hi = n*m, res = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int cnt = cnt_leq_x(a,mid);
            if (mid - cnt >= x) {
                res = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        assert(res != -1);
        a.push_back(res);
        sort(a.begin(), a.end());
        int r = res / m, c = res % m;
        vector<int> ret = {r,c};
        return ret;
    }
    
    void reset() {
        a.clear();
        sz = n*m;        
    }
};
