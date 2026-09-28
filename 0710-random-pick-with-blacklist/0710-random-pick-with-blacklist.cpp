mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cnt(vector<int> &a, int x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

class Solution {
public:
    int n,sz;
    vector<int> a;
    Solution(int n, vector<int>& b) {
        this->n = n;
        a = b;
        sort(a.begin(), a.end());
        this->sz = a.size();
        // cout << sz << endl;
        // cout << n - sz << endl;
    }
    
    int pick() {
        int x = rng() % (n-sz);
        int lo = 0, hi = n-1, ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            int y = mid;
            // cout << x << " " << cnt(a,y) << " " << y << endl;
            if (x + cnt(a,y) <= y) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};