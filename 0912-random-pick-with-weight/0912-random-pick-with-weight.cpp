mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
public:
    int n, mod;
    vector<int> p;
    Solution(vector<int>& w) {
        n = w.size();
        p.assign(n+1,0);
        for (int i=0; i<n; i++) {
            p[i+1] = p[i] + w[i];
        }
        mod = p.back();
    }
    
    int pickIndex() {
        int x = rng() % mod;
        auto it = upper_bound(p.begin(), p.end(), x);
        return it - p.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */