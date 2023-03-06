class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int n = a.size(), lo = 0, hi = n-1, idx = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (a[mid]-mid-1 < k) {
                idx = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return idx==-1 ? k : k+idx+1;
    }
};  