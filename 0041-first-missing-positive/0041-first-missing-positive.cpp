class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        a.push_back(-1);
        for (int i=0; i<n; i++) {
            while (a[i] != i && 1 <= a[i] && a[i] <= n) {
                int j = a[i];
                if (a[j] != a[i]) swap(a[i], a[j]);
                else break;
            }
        }
        for (int i=1; i<=n; i++) {
            if (a[i] != i) return i;
        }
        return n+1;
    }
};