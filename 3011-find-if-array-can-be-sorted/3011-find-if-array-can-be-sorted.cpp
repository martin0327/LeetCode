class Solution {
public:
    void debug(vector<int> &a) {
        for (auto x : a) {
            cout << x << " ";
        }   cout <<endl;
    }
    bool canSortArray(vector<int>& a) {
        int n = a.size();
        auto cnt = [&] (int x) {
            return __builtin_popcount(x);
        };
        
        for (int i=1; i<n; i++) {
            for (int j=1; j<n; j++) {
                int x = a[j-1];
                int y = a[j];
                if (cnt(x) == cnt(y) && x > y) {
                    swap(a[j-1],a[j]);
                }
            }
            // debug(a);
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        return a == b;        
    }
};