using vi = vector<int>;
class Solution {
public:
    void debug(vi &a) {
        for (auto &x : a) cout << x << " ";
        cout << endl;
    }
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        if (k<=1) return 0;
        int n = a.size();
        int ans=0, i=0, j=0, p=1;
        vector<int> left(n+1, -1);
        while (i < n) {
            if (j < n && p < k) p *= a[j++];
            else p /= a[i++];
            if (j <= n && p < k && left[j] == -1) left[j] = i;
            // vi t = {i,j,p};
            // debug(t);
        }
        // debug(left);
        for (int j=1; j<=n; j++) ans += j - left[j];
        return ans;
    }
};