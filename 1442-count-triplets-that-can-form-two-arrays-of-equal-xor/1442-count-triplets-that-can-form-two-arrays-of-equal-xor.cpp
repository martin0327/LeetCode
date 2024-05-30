class Solution {
public:
    int countTriplets(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n+1);
        for (int i=1; i<=n; i++) pre[i] = pre[i-1] ^ a[i-1];
        int ans = 0;
        for (int k=1; k<=n; k++) {
            for (int i=1; i<k; i++) {
                if (pre[i-1] == pre[k]) ans += k-i;
            }      
        }
        return ans;
    }
};

// pre[k] ^ pre[j-1] == pre[j-1] ^ pre[i-1]