using vi = vector<int>;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        if (k<=1) return 0;
        int n = a.size();
        int ans=0, i=0, j=0, p=1;
        while (i < n) {
            if (j < n && p < k) p *= a[j++];
            else p /= a[i++];
            if (p < k) {
                ans += j - i;
                if (j==n) break;
            }
        }
        return ans;
    }
};