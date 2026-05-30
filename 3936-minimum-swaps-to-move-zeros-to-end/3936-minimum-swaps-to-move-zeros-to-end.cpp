class Solution {
public:
    int minimumSwaps(vector<int>& a) {
        int n = a.size(), ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i] == 0) {
                int idx = -1;
                for (int j=n-1; j>i; j--) {
                    if (a[j] != 0) {
                        idx = j;
                        break;
                    }
                }
                if (idx != -1) {
                    ans++;
                    swap(a[i],a[idx]);
                }
            }
        }
        return ans;
    }
};