class Solution {
public:
    void debug(vector<int> &a) {
        for (auto x : a) {
            cout << x << " ";
        }   cout << endl;
    }
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            while (a[i] != i+1 && 1 <= a[i] && a[i] <= n) {
                if (a[a[i]-1] != a[i]) swap(a[i], a[a[i]-1]);
                else break;
            }
            // debug(a);
        }
        for (int i=0; i<n; i++) {
            if (a[i] != i+1) return i+1;
        }
        return n+1;
        
    }
};