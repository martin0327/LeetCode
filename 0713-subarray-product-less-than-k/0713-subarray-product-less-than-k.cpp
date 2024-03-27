using vi = vector<int>;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        if (k<=1) return 0;
        int n = a.size(), ans = 0, p = 1;
        for (int i=0, j=0; j<n; j++) {
            p *= a[j];
            while (p >= k) p /= a[i++];
            ans += j-i+1;
        }
        return ans;
    }
};