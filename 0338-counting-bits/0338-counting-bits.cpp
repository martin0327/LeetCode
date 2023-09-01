class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> a(n+1);
        for (int i=1; i<=n; i++) a[i] = a[i-(i&-i)] + 1;
        return a;
    }
}; 