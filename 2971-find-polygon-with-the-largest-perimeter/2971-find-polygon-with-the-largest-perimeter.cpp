using ll = long long;
class Solution {
public:
    long long largestPerimeter(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<ll> pre(n+1);
        a.insert(a.begin(), 0ll);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i];
        for (int i=n; i>=3; i--) {
            if (a[i] < pre[i-1]) return pre[i];
        }
        return -1;
    }
};
