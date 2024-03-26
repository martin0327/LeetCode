class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            while (a[i] != i+1 && 1 <= a[i] && a[i] <= n) {
                int j = a[i] - 1;
                if (a[j] != a[i]) swap(a[i], a[j]);
                else break;
            }
        }
        for (int i=0; i<n; i++) {
            if (a[i] != i+1) return i+1;
        }
        return n+1;
    }
};